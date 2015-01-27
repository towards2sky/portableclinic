<?php

/**
 * Function to check existence of mPDF library.
 *
 * @return bool
 *   TRUE if mPDF library path exists and FALSE if it isn't.
 */
function user_generate_library_exist() {
    $tools = array();

    // Search for mpdf tool first.
    $pattern = '/^PDFMerger.php$/';

    // Libraries module to detect mPDF library in case of multisite installation.
    $tools = array_keys(file_scan_directory(libraries_get_path('PDFMerger'), $pattern));

    // mPDF library looked for in the module directory itself.
    $tools = array_merge($tools, array_keys(file_scan_directory(drupal_get_path('module', 'user_generate'), $pattern)));

    if (isset($tools[0])) {
        require_once $tools[0];
        return TRUE;
    } else {
        return FALSE;
    }
}

function generate_pdf() {
    global $user;
    user_generate_library_exist();

    
    $obj = array();
    $obj['name'] = 'Rajesh Saini';
    $obj['gender'] = 'Male';
    $obj['dob'] = get_dob("01/07/1985", '/');
    $obj['profession'] = 'Software Engg.';
    $obj['mobile'] = '9410093032';
    $obj['patient_email'] = 'a_sharma@indiabookofrecords.in';
    $obj['pulse_rate'] = '200';
    $obj['bp_higher'] = 120;
    $obj['bp_lower'] = 80;;
    $obj['bmi'] = '42';
    $obj['medical_condition'] = 'Fever';
    $obj['daily_Raw_food'] = '10-20 %';
    $obj['daily_fruit_juices'] = 'Freshly squeezed fruit juice';
    $obj['breakfast_raw_food'] = '10-20 %';
    $obj['breakfast_fruit_juices'] = 'Packed fruit juices';    
    $obj['lunch_raw_food'] = '20-30 %';
    $obj['dinner_raw_food'] = '20-30 %';
    $obj['snacks_raw_food'] = '10-20 %';
    $obj['snacks_fruit_juices'] = 'Packed fruit juices';
    $obj['physical_work'] = '10-30min/day';
    $obj['physical_sleep'] = 'Regular';
    $obj['medication'] = 'Are you currently taking any medicine:' .'Yes';
    $obj['medication_taken'] = 'No';
    $obj['family_medication_condition'] = 'Yes';
    
    
    $mbi_dir_path = "public://bmi";
    $dir_path = "public://bmi/bydoctor/$user->uid/";

    if (!file_prepare_directory($dir_path, FILE_CREATE_DIRECTORY)) {
        exit('Invalid file path');
    }
    file_prepare_directory($dir_path);
    $path = drupal_realpath($dir_path);
    $bmi_path = drupal_realpath($mbi_dir_path);
    drupal_chmod($path);

    $bg = $bmi_path . '/default/background.jpg';
    $first_page_pdf = $path . '/first_page.pdf';



    if (file_exists($first_page_pdf)) {
        unlink($first_page_pdf);
    }


    // initiate FPDI 
    $pdf = new FPDI('P', 'mm', 'A4');
    // add a page 
    $pdf->AddPage();
    // set the sourcefile 
    $pdf->Image($bg, 0, 0, 210, 297);
    $pdf->SetFont('arial', '', 12);
    $x = 10;
    $y = 68;
    $line_diff = 13;
    $second_word = 65;
    $third_word = 110;
    $v = 25;

    
    // First Line   /---
    
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Name:');

    $x = $x + $v;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, $obj['name']);
    $x = $x - $v;

    //$y = $y+$line_diff;
    $x = $x + $second_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Gender: ' . $obj['gender']);
    
    $x = $x - $second_word;
    //$y = $y + $line_diff;
    $x = $x+$third_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Age: '.$obj['dob'].' years');
    $x = $x-$third_word;
    
            // Second Line
    
//    $y = $y + $line_diff;
//    $pdf->SetXY($x, $y);
//    $pdf->Write(0, 'Profession:');
//
//    $x = $x + $v;
//    $pdf->SetXY($x, $y);
//    $pdf->Write(0, $obj['profession']);
//    $x = $x - $v;

    
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Mobile:');

    $x = $x + $v;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, $obj['mobile']);
    $x = $x - $v;


    //$y = $y + $line_diff;
    $x = $x + $second_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Email:  ' . $obj['patient_email']);
    $x = $x - $second_word;

//    $x = $x + $third_word;
//    $pdf->SetXY($x, $y);
//    $pdf->Write(0, 'Email:  ' . $obj['patient_email']);

    // Third Line

    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Pulse Rate:');

    $x = $x + $v;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, $obj['pulse_rate']);
    $x = $x - $v;

    //$y = $y + $line_diff;
    $x = $x + $second_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'B.P(Higher): '.$obj['bp_higher']);
    $x = $x - $second_word;
    
    
    $x = $x + $third_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'B.P(Lower): '.$obj['bp_lower']);
    $x = $x - $third_word;
    
    // Fourth Line
    
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'BMI:');
    
    $x = $x + $v;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, $obj['bmi']);
    $x = $x - $v;
    
    
    $x = $x + $second_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Medical Condition: ' . $obj['medical_condition']);
    $x = $x - $second_word;
    
    $extra_y = 5;
    $extra_x = 5;
    // 5th line
    $pdf->SetFont('arial', 'B', 12);
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Daily Eating Pattern');
    
    $pdf->SetFont('arial', '', 12);

    //// 6th line
    $y = $y + $line_diff-$extra_y;
    $x = $x+$extra_x;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Raw Food: '.$obj['daily_Raw_food']);
    


    //$y = $y + $line_diff;
    $x = $x + $second_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Fruit Juices : '.$obj['daily_fruit_juices']);
    $x = $x - $second_word;
    $x = $x-$extra_x;
    // 7th Line
    
    $pdf->SetFont('arial', 'B', 12);
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Lunch');
    $pdf->SetFont('arial', '', 12);
    
    $y = $y + $line_diff-$extra_y;
    $x = $x+$extra_x;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Raw Food: '.$obj['lunch_raw_food']);
    $x = $x-$extra_x;
    //$x = $x - 20;
    // 8th Line
    $pdf->SetFont('arial', 'B', 12);
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Dinner');
    $pdf->SetFont('arial', '', 12);
    
    $y = $y + $line_diff-$extra_y;
    $x = $x+$extra_x;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Raw Food: '.$obj['dinner_raw_food']);
    $x = $x-$extra_x;
    
    //9 th Line
    $pdf->SetFont('arial', 'B', 12);
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Snacks');
    $pdf->SetFont('arial', '', 12);
    
    
    $y = $y + $line_diff-$extra_y;
    $x = $x+$extra_x;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Raw Food: '.$obj['snacks_raw_food']);
    


    //$y = $y + $line_diff;
    $x = $x + $second_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Fruit Juices : '.$obj['snacks_fruit_juices']);
    $x = $x - $second_word;
    $x = $x-$extra_x;
    
        //10 th Line
    $pdf->SetFont('arial', 'B', 12);
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Physical Activity');
    $pdf->SetFont('arial', '', 12);
    
    
    $y = $y + $line_diff-$extra_y;
    $x = $x+$extra_x;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Physical Work: '.$obj['physical_work']);

    //$y = $y + $line_diff;
    $x = $x + $second_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Sleep Pattern : '.$obj['physical_sleep']);
    $x = $x - $second_word;
    $x = $x-$extra_x;

    
        //11 th Line
    $pdf->SetFont('arial', 'B', 12);
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Medication');
    $pdf->SetFont('arial', '', 12);
    
    
    $y = $y + $line_diff-$extra_y;
    $x = $x+$extra_x;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Are you currently taking any medicine: '.$obj['medication_taken']);
     $x = $x-$extra_x;    
    //$y = $y + $line_diff;
    
    $pdf->SetFont('arial', 'B', 12);
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Family History');
    $pdf->SetFont('arial', '', 12);
    $x = $x+$extra_x;
    $y = $y + $line_diff-$extra_y;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Is any one from your Family has a history of any medical condition: '.$obj['family_medication_condition']);
    $x = $x - $second_word;
    $x = $x-$extra_x;    
    

    $pdf->Output($first_page_pdf, 'D');
    exit
    ;
}

function _prepair_first_bmi_pdf($obj) {
    global $user;
   
  //   drupal_set_message('saini saini');
   // user_generate_library_exist();
   // 
   require_once(libraries_get_path('fpdf').'/fpdf.php');
   require_once(libraries_get_path('fpdi').'/fpdi.php');
    //  $bg = 'public://bmi/files/bmi/default/background.jpg';
    $mbi_dir_path = "public://bmi";
    $bmi = trim($obj['bmi']);
    $medical_condition = _user_generate_get_medical_condition_dir($obj['medical_condition']);
    
    // $destination =  "public://bmi/byadmin/$bmi/$medical_condition";

    $dir_path = "public://bmi/bydoctor/$user->uid/";

    if (!file_prepare_directory($dir_path, FILE_CREATE_DIRECTORY)) {
        exit('Invalid file path');
    }

    $path = drupal_realpath($dir_path);
    $bmi_path = drupal_realpath($mbi_dir_path);
    drupal_chmod($path);
    
    $bg = $bmi_path . '/default/background.jpg';
    $first_page_pdf = $path . '/first_page.pdf';

    if (file_exists($first_page_pdf)) {
        unlink($first_page_pdf);
    }
     
    if (file_exists("$path/final.pdf")) {
        unlink("$path/final.pdf");
    }
    
    // initiate FPDI 
    $pdf = new FPDI('P', 'mm', 'A4');
    // add a page 
    $pdf->AddPage();
    // set the sourcefile 
    $pdf->Image($bg, 0, 0, 210, 297);
    $pdf->SetFont('arial', '', 12);
    $x = 10;
    $y = 68;
    $line_diff = 13;
    $second_word = 65;
    $third_word = 110;
    $v = 25;

    // First Line   /---
    
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Name:');

    $x = $x + $v;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, $obj['name']);
    $x = $x - $v;

    //$y = $y+$line_diff;
    $x = $x + $second_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Gender: ' . $obj['gender']);
    
    $x = $x - $second_word;
    //$y = $y + $line_diff;
    $x = $x+$third_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Age: '.$obj['dob'].' years');
    $x = $x-$third_word;
    
           // Second Line
    
//    $y = $y + $line_diff;
//    $pdf->SetXY($x, $y);
//    $pdf->Write(0, 'Profession:');
//
//    $x = $x + $v;
//    $pdf->SetXY($x, $y);
//    $pdf->Write(0, $obj['profession']);
//    $x = $x - $v;

    
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Mobile:');

    $x = $x + $v;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, $obj['mobile']);
    $x = $x - $v;


    //$y = $y + $line_diff;
    $x = $x + $second_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Email:  ' . $obj['patient_email']);
    $x = $x - $second_word;

//    $x = $x + $third_word;
//    $pdf->SetXY($x, $y);
//    $pdf->Write(0, 'Email:  ' . $obj['patient_email']);
    // Third Line

    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Pulse Rate:');

    $x = $x + $v;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, $obj['pulse_rate']);
    $x = $x - $v;

    //$y = $y + $line_diff;
    $x = $x + $second_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'B.P(Higher): '.$obj['bp_higher']);
    $x = $x - $second_word;
    
    
    $x = $x + $third_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'B.P(Lower): '.$obj['bp_lower']);
    $x = $x - $third_word;
    
    // Fourth Line
    
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'BMI:');
    
    $x = $x + $v;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, $obj['bmi']);
    $x = $x - $v;
    
    $x = $x + $second_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Medical Condition: ' . $obj['medical_condition']);
    $x = $x - $second_word;
    
    $extra_y = 5;
    $extra_x = 5;
    // 5th line
    $pdf->SetFont('arial', 'B', 12);
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Daily Eating Pattern');
    $pdf->SetFont('arial', '', 12);

    //// 6th line
    $y = $y + $line_diff-$extra_y;
    $x = $x+$extra_x;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Raw Food: '.$obj['daily_Raw_food']);
    //$y = $y + $line_diff;
    $x = $x + $second_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Fruit Juices : '.$obj['daily_fruit_juices']);
    $x = $x - $second_word;
    $x = $x-$extra_x;
    // 7th Line
    
    $pdf->SetFont('arial', 'B', 12);
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Lunch');
    $pdf->SetFont('arial', '', 12);
    
    $y = $y + $line_diff-$extra_y;
    $x = $x+$extra_x;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Raw Food: '.$obj['lunch_raw_food']);
    $x = $x-$extra_x;
    //$x = $x - 20;
    // 8th Line
    $pdf->SetFont('arial', 'B', 12);
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Dinner');
    $pdf->SetFont('arial', '', 12);
    
    $y = $y + $line_diff-$extra_y;
    $x = $x+$extra_x;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Raw Food: '.$obj['dinner_raw_food']);
    $x = $x-$extra_x;
    
    //9 th Line
    $pdf->SetFont('arial', 'B', 12);
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Snacks');
    $pdf->SetFont('arial', '', 12);
    
    
    $y = $y + $line_diff-$extra_y;
    $x = $x+$extra_x;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Raw Food: '.$obj['snacks_raw_food']);
    


    //$y = $y + $line_diff;
    $x = $x + $second_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Fruit Juices : '.$obj['snacks_fruit_juices']);
    $x = $x - $second_word;
    $x = $x-$extra_x;
    
        //10 th Line
    $pdf->SetFont('arial', 'B', 12);
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Physical Activity');
    $pdf->SetFont('arial', '', 12);
    
    
    $y = $y + $line_diff-$extra_y;
    $x = $x+$extra_x;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Physical Work: '.$obj['physical_work']);

    //$y = $y + $line_diff;
    $x = $x + $second_word;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Sleep Pattern : '.$obj['physical_sleep']);
    $x = $x - $second_word;
    $x = $x-$extra_x;

    
        //11 th Line
    $pdf->SetFont('arial', 'B', 12);
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Medication');
    $pdf->SetFont('arial', '', 12);
    
    
    $y = $y + $line_diff-$extra_y;
    $x = $x+$extra_x;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Are you currently taking any medicine: '.$obj['medication_taken']);
     $x = $x-$extra_x;    
    //$y = $y + $line_diff;
    
    $pdf->SetFont('arial', 'B', 12);
    $y = $y + $line_diff;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Family History');
    $pdf->SetFont('arial', '', 12);
    $x = $x+$extra_x;
    $y = $y + $line_diff-$extra_y;
    $pdf->SetXY($x, $y);
    $pdf->Write(0, 'Is any one from your Family has a history of any medical condition: '.$obj['family_medication_condition']);
    $x = $x - $second_word;
    $x = $x-$extra_x;    

    $pdf->Output($first_page_pdf, 'F');

  //  $default_path = $bmi_path . "/byadmin/$bmi/$medical_condition/second_part.pdf";
   
   // $first_page_pdf;
//if (file_exists($first_page_pdf) && file_exists($default_path)) {
//    echo  $first_page_pdf;
//}    
// p($obj); exit;
//    if (file_exists($first_page_pdf) && file_exists($default_path)) {
//        // create final file for sant to user
//        if (file_exists("$path/final.pdf")) {
//            unlink("$path/final.pdf");
//        }
//        $Margepdf = new PDFMerger;
//        $default_path = $bmi_path . "/byadmin/$bmi/$medical_condition/second_part.pdf";
//     
//     
//        $Margepdf->addPDF($first_page_pdf)
//                ->addPDF($default_path)
//                ->merge('file', $path . '/final.pdf');
//        if (file_exists($path . '/final.pdf')) {
//           
//            // return $path.'/final.pdf'; 
//        } else {
//            drupal_set_message('Error in genearte final bmi pdf. Try again');
//            drupal_goto();
//        }
//        
//       //  p($obj); exit;
//    } else {
//       // drupal_set_message('No Prescription found this BMI amd Medical Condition. Contact to Admin');
//        // drupal_goto();
//    }
}

function _prepair_final_bmi_pdf($obj){
    
    require_once(libraries_get_path('tcpdf').'/tcpdf.php');
    require_once(libraries_get_path('tcpdi').'/tcpdi.php');
    global $user;
    $mbi_dir_path = "public://bmi";
    $bmi = trim($obj['bmi']);
    $medical_condition = _user_generate_get_medical_condition_dir($obj['medical_condition']);
    
    $dir_path = "public://bmi/bydoctor/$user->uid/";

    $path = drupal_realpath($dir_path);
    $bmi_path = drupal_realpath($mbi_dir_path);
    drupal_chmod($path);

    $first_page_pdf = $path . '/first_page.pdf';
    
    //---------------------------------------
     $default_path = $bmi_path . "/byadmin/$bmi/$medical_condition/second_part.pdf";
     
     
    if (file_exists($first_page_pdf) && file_exists($default_path)) {
        // create final file for sant to user
        if (file_exists("$path/final.pdf")) {
            unlink("$path/final.pdf");
        }
        
       $pdf = new TCPDI(PDF_PAGE_ORIENTATION, PDF_UNIT, PDF_PAGE_FORMAT, true, 'UTF-8', false);
// Add a page from a PDF by file path.
       $pdf->AddPage();
        
        $pdf->setSourceFile($first_page_pdf);
        $idx = $pdf->importPage(1);
        $pdf->useTemplate($idx);

$pdfdata = file_get_contents($default_path); // Simulate only having raw data available.

$pagecount = $pdf->setSourceData($pdfdata); 
for ($i = 1; $i <= $pagecount; $i++) { 
    $tplidx = $pdf->importPage($i);
    $pdf->AddPage();
    $pdf->useTemplate($tplidx); 
}

$pdf->Output("$path/final.pdf", 'F');

        if (file_exists($path . '/final.pdf')) {
           
            // return $path.'/final.pdf'; 
             //drupal_set_message('Final file exist');
        } else {
            drupal_set_message('Error in genearte final bmi pdf. Try again');
            drupal_goto();
        }
        
       //  p($obj); exit;
    } else {
       // drupal_set_message('No Prescription found this BMI amd Medical Condition. Contact to Admin');
        // drupal_goto();
    }
}

function _user_generate_get_medical_condition_dir($medical_condition) {

     $dir = str_replace(' ', '_',strtolower(trim($medical_condition)));
     return $dir;
}




function get_dob($birthDate, $seperator) {
    
    //$birthDate = "01/07/1985";
    //explode the date to get month, day and year
    $birthDate = explode($seperator, $birthDate);
    //get age from date or birthdate
    $age = (date("md", date("U", mktime(0, 0, 0, $birthDate[0], $birthDate[1], $birthDate[2]))) > date("md") ? ((date("Y") - $birthDate[2]) - 1) : (date("Y") - $birthDate[2]));
    
    return $age;
    
}

function get_field_value($val){
    if(isset($val) && $val!= '') {
        return $val;
    }
    else {
        return 'Not Mentioned';
    }
}

function get_field_value_row($val){
    if(isset($val) && $val!= '') {
        return $val.' %';
    }
    else {
        return 'Not Mentioned';
    }
}