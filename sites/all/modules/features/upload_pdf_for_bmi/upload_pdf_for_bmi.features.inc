<?php
/**
 * @file
 * upload_pdf_for_bmi.features.inc
 */

/**
 * Implements hook_views_api().
 */
function upload_pdf_for_bmi_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function upload_pdf_for_bmi_node_info() {
  $items = array(
    'upload_pdf_for_bmi' => array(
      'name' => t('Upload PDF For BMI & MEDICAL'),
      'base' => 'node_content',
      'description' => t('Upload BMI PDF'),
      'has_title' => '1',
      'title_label' => t('BMI'),
      'help' => '',
    ),
  );
  return $items;
}
