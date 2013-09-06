<?php
/**
 * @file
 * upload_bmi_pdf.features.inc
 */

/**
 * Implements hook_views_api().
 */
function upload_bmi_pdf_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function upload_bmi_pdf_node_info() {
  $items = array(
    'upload_bmi_pdf' => array(
      'name' => t('Upload BMI PDF'),
      'base' => 'node_content',
      'description' => t('pdf upload for bmi '),
      'has_title' => '1',
      'title_label' => t('BMI'),
      'help' => '',
    ),
  );
  return $items;
}
