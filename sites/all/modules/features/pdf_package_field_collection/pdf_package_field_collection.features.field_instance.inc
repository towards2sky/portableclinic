<?php
/**
 * @file
 * pdf_package_field_collection.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function pdf_package_field_collection_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'field_collection_item-field_pdf_package-field_age_type'
  $field_instances['field_collection_item-field_pdf_package-field_age_type'] = array(
    'bundle' => 'field_pdf_package',
    'default_value' => NULL,
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_age_type',
    'label' => 'Age type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_pdf_package-field_gender'
  $field_instances['field_collection_item-field_pdf_package-field_gender'] = array(
    'bundle' => 'field_pdf_package',
    'default_value' => NULL,
    'default_value_function' => '',
    'default_value_php' => '',
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
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_gender',
    'label' => 'Gender',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_pdf_package-field_pdf'
  $field_instances['field_collection_item-field_pdf_package-field_pdf'] = array(
    'bundle' => 'field_pdf_package',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_pdf',
    'label' => 'PDF',
    'required' => 1,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'defaultbmipdf',
      'file_extensions' => 'pdf',
      'max_filesize' => '10 MB',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'field_collection_item-field_pdf_package-field_pdf_medical_condition'
  $field_instances['field_collection_item-field_pdf_package-field_pdf_medical_condition'] = array(
    'bundle' => 'field_pdf_package',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_pdf_medical_condition',
    'label' => 'Medical Condition',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Age type');
  t('Gender');
  t('Medical Condition');
  t('PDF');

  return $field_instances;
}
