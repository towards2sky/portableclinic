<?php
/**
 * @file
 * patient_assessment_form.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function patient_assessment_form_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function patient_assessment_form_node_info() {
  $items = array(
    'patient_assessment_form' => array(
      'name' => t('Patient Assessment Form'),
      'base' => 'node_content',
      'description' => t('Patient Assessment Form'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
