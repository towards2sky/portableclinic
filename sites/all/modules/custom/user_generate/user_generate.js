jQuery( document ).ready(function($) {
    $('#field-bmi-add-more-wrapper').append( "<div id='bmi-info'></div>" );
    $("#edit-field-weight-kg-und" ).change(function() {
        if(check_values()){calculate_bmi();}
    });
   $("#edit-field-height-m-und" ).change(function() {
       if(check_values()){ calculate_bmi();}
    }); 
     
function check_values(){
    if( $("#edit-field-weight-kg-und" ).val() == '_none'){
        return 0;
    }
    if( $("#edit-field-height-m-und" ).val() == '_none'){
        return 0;
    }
    return 1;
}

function calculate_bmi(){
    var weight = parseInt($("#edit-field-weight-kg-und" ).val());
    var height = $("#edit-field-height-m-und" ).val().split('_');
    var height_inch = (((parseInt(height[0])*12)+parseInt(height[1])));
    var height_m = ( (height_inch) * (0.0254) );
    var bmi = (weight/(height_m*height_m));
    var decimalbmi = parseFloat(bmi).toFixed(2);
    var temp_bmi = decimalbmi.split('.');
        if((temp_bmi[1]) >  49 ){
            var finalbmi = parseInt(temp_bmi[0])+1;
        }else {
            var finalbmi = temp_bmi[0];
        }
    $('#edit-field-bmi-und-0-value').val(finalbmi);
}

function bmistatus(bmi) {
    var info = '';
		if (bmi < 15) {
			info = "very severely underweight";
		}
		if ((bmi >= 15)&&(bmi < 16)) {
			info = "severely underweight";
		}
		if ((bmi >= 16)&&(bmi < 18.5)) {
			info = "underweight";
		}
		if ((bmi >= 18.5)&&(bmi < 25)) {
			info = "normal";
		}
		if ((bmi >= 25)&&(bmi < 30)) {
			info = "overweight";
		}
		if ((bmi >= 30)&&(bmi < 35)) {
			info = "moderately obese";
		}
		if ((bmi >= 35)&&(bmi <= 40)) {
			info = "severely obese";
		}
		if (bmi >40) {
			info = "very severely obese";
		}    
}

// HOBs coefficent
$("#node_patient_assessment_form_form_group_hobs_coefficient").hide();
$("#node_patient_assessment_form_form_group_bmi").hide(); 
   $("#edit-field-week-type-und" ).change(function() {
    if( $("#edit-field-week-type-und" ).val() == '_none'){
        $("#node_patient_assessment_form_form_group_hobs_coefficient").hide();
        $("#node_patient_assessment_form_form_group_bmi").hide(); 
    }else if ($("#edit-field-week-type-und" ).val() == 'Week3') {
        $("#node_patient_assessment_form_form_group_bmi").hide();
        $("#node_patient_assessment_form_form_group_hobs_coefficient").show();
    } else {
        $("#node_patient_assessment_form_form_group_hobs_coefficient").hide();
        $("#node_patient_assessment_form_form_group_bmi").show();
    }
    });
        
function hobs_perameter_is_ready(){
    if( $("#edit-field-previous-weight-und" ).val() == '_none'){
        return 0;
    }
    if( $("#edit-field-present-weight-und" ).val() == '_none'){
        return 0;
    }
    return 1;
}    
    

function calculate_hobs(){
    var previous_weight = parseInt($("#edit-field-previous-weight-und" ).val());
    var present_weight = parseInt($("#edit-field-present-weight-und" ).val());
    var hobs_value = (parseInt(previous_weight-present_weight)*100)/previous_weight;
    //alert(hobs_value);
    if(hobs_value < 1){
	hobs_value = 0;	
	}
    if(parseInt(hobs_value) === hobs_value){
	var final_hobs_value = hobs_value;
	}else {
    var final_hobs_value = hobs_value.toFixed(1);
	}
    $('#edit-field-hobs-coefficient-value-und-0-value').val(final_hobs_value);
}
    
$("#edit-field-previous-weight-und" ).change(function() {
        if(hobs_perameter_is_ready()){calculate_hobs();}
    });
$("#edit-field-present-weight-und" ).change(function() {
       if(hobs_perameter_is_ready()){ calculate_hobs();}
    });
    
/// Validation for BMI & HOBS    
$("#edit-submit").click(function() {

    if( $("#edit-field-week-type-und" ).val() == '_none'){
        alert( "Please select week type." );
        return false;
    }else if ($("#edit-field-week-type-und" ).val() == 'Week3') {
        if(!$("#edit-field-hobs-coefficient-value-und-0-value").val()){
               alert("Hobs coefficient value should not be empty.");
               return false;
         }
    } else if (($("#edit-field-week-type-und" ).val() == 'Week1') && ($("#edit-field-week-type-und" ).val() == 'Week2')) {
        if(!$("#edit-field-bmi-und-0-value").val()){
               alert("BMI should not be empty.");
               return false;
        }
    } else {
        // do nothing
        return 
    }

});


});

