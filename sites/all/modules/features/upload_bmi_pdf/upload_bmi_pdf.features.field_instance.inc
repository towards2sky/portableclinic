<?php
/**
 * @file
 * upload_bmi_pdf.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function upload_bmi_pdf_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-upload_bmi_pdf-field_bmi_upload_pdf'
  $field_instances['node-upload_bmi_pdf-field_bmi_upload_pdf'] = array(
    'bundle' => 'upload_bmi_pdf',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_bmi_upload_pdf',
    'label' => 'Upload PDF',
    'required' => 1,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => -1,
    ),
  );

  // Exported field_instance: 'node-upload_bmi_pdf-field_pdf_medical_condition'
  $field_instances['node-upload_bmi_pdf-field_pdf_medical_condition'] = array(
    'bundle' => 'upload_bmi_pdf',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pdf_medical_condition',
    'label' => 'Medical Condition',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'cck_select_other',
      'settings' => array(
        'select_list_options' => 'other|Other',
        'select_list_options_fieldset' => array(
          'advanced_options' => array(
            'select_list_options_php' => '           $add_medical_condition = db_select(\'node\', \'n\')
                    ->fields(\'n\', array(\'title\'))
                    ->condition(\'type\', \'add_medical_condition\')
                    ->orderBy(\'title\', \'ASC\')
                    ->execute()
                    ->fetchAll();
            foreach ($add_medical_condition as $obj) {
                $option_values[$obj->title] = $obj->title;
            }
 return  $option_values;',
          ),
        ),
      ),
      'type' => 'cck_select_other',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Medical Condition');
  t('Upload PDF');

  return $field_instances;
}
