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
  }
  else {
    return FALSE;
  }
}

function generate_pdf(){
        global $user;
        user_generate_library_exist();
      //  $bg = 'public://bmi/files/bmi/default/background.jpg';
        $mbi_dir_path = "public://bmi";
        $dir_path = "public://bmi/bydoctor/$user->uid/";
        
        if(!file_prepare_directory($dir_path, FILE_CREATE_DIRECTORY)){
            exit('Invalid file path');
        } 
        file_prepare_directory($dir_path);
        $path = drupal_realpath($dir_path);
        $bmi_path = drupal_realpath($mbi_dir_path);
        drupal_chmod($path);
        
        $bg = $bmi_path.'/default/background.jpg';
        $first_page_pdf = $path.'/first_page.pdf';
        
        if (file_exists($first_page_pdf)) { unlink($first_page_pdf); }
        
    
    // initiate FPDI 
	$pdf = new FPDI('P','mm','A4'); 
	// add a page 
        $pdf->AddPage(); 
        // set the sourcefile 
        $pdf->Image($bg, 0, 0, 210, 297); 
        $pdf->SetFont('Arial', '', 16); 
        $x = 25; $y = 80; $line_diff = 10; 
        
        $name = "Rajesh Saini"; 
        $pdf->SetXY($x, $y);
	$pdf->Write(0, 'Name: '.$name); 
        
        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'Gender:'); 
        
        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'DOB:'); 
        
        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'Profession:'); 
        
        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'Mobile:'); 
        
        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'Email:'); 

        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'Pulse Rate:');

        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'Blood Pressure Systolic (Higher):');

        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'Blood Pressure Diastolic (Lower):');
        
        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'Medical Condition:');
        
        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'BMI:');
                
	$pdf->Output( $first_page_pdf, 'F'); 
        
        // create final file for sant to user
       if (file_exists("$path/final.pdf")) { unlink("$path/final.pdf"); }
        $Margepdf = new PDFMerger;
        $default_path = $bmi_path.'/bmi/byadmin/second_part.pdf';
        $Margepdf->addPDF($first_page_pdf)
	->addPDF($default_path)	
	->merge('file', $path.'/final.pdf');
    
}


function prepair_final_bmi_pdf($obj){
        global $user;
       
        user_generate_library_exist();
      //  $bg = 'public://bmi/files/bmi/default/background.jpg';
        $mbi_dir_path = "public://bmi";
        $bmi = trim($obj['bmi']);
        $medical_condition = str_replace(' ', '_', trim($obj['medical_condition']));
       // $destination =  "public://bmi/byadmin/$bmi/$medical_condition";
        
        $dir_path = "public://bmi/bydoctor/$user->uid/";
        
        if(!file_prepare_directory($dir_path, FILE_CREATE_DIRECTORY)){
            exit('Invalid file path');
        } 
        
        $path = drupal_realpath($dir_path);
        $bmi_path = drupal_realpath($mbi_dir_path);
        drupal_chmod($path);
        
        $bg = $bmi_path.'/default/background.jpg';
        $first_page_pdf = $path.'/first_page.pdf';
        
        if (file_exists($first_page_pdf)) { unlink($first_page_pdf); }
        
    // initiate FPDI 
	$pdf = new FPDI('P','mm','A4'); 
	// add a page 
        $pdf->AddPage(); 
        // set the sourcefile 
        $pdf->Image($bg, 0, 0, 210, 297); 
        $pdf->SetFont('Arial', '', 16); 
        $x = 25; $y = 80; $line_diff = 10; 
        
        $pdf->SetXY($x, $y);
	$pdf->Write(0, 'Name: '.$obj['name']); 
        
        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'Gender: '.$obj['gender']); 
        
        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'DOB: '.$obj['dob']); 
        
        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'Profession: '.$obj['profession']); 
        
        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'Mobile: '.$obj['mobile']); 
        
        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'Email: '.$obj['patient_email']); 

        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'Pulse Rate: '.$obj['pulse_rate']);

        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'Blood Pressure Systolic (Higher): '.$obj['blood_pressure_systolic']);

        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'Blood Pressure Diastolic (Lower): '.$obj['blood_pressure_diastolic']);
        
        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'Medical Condition: '.$obj['medical_condition']);
        
        $y = $y+$line_diff;
        $pdf->SetXY($x, $y); 
	$pdf->Write(0, 'BMI: '.$obj['bmi']);
                
	$pdf->Output( $first_page_pdf, 'F'); 
        
        if (file_exists($first_page_pdf)) { 
        // create final file for sant to user
       if (file_exists("$path/final.pdf")) { unlink("$path/final.pdf"); }
            $Margepdf = new PDFMerger;
            $default_path = $bmi_path."/byadmin/$bmi/$medical_condition/second_part.pdf";
            $Margepdf->addPDF($first_page_pdf)
            ->addPDF($default_path)	
            ->merge('file', $path.'/final.pdf');
              if (file_exists($path.'/final.pdf')) { 
                 // return $path.'/final.pdf'; 
              }  else {
                    drupal_set_message('Error in genearte final bmi pdf. Try again');
                    drupal_goto();
              }
        } else {
            drupal_set_message('Error in genearte persional bmi pdf. Try again');
            drupal_goto();
        }
    
}