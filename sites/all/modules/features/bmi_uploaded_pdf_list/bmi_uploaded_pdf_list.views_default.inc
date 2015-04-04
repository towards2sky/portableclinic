<?php
/**
 * @file
 * bmi_uploaded_pdf_list.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function bmi_uploaded_pdf_list_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'bmi_uploaded_pdf_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'BMI UPLOADED PDF LIST';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'BMI PDF LIST';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_gender' => 'field_gender',
    'field_age_type' => 'field_age_type',
    'field_pdf_medical_condition' => 'field_pdf_medical_condition',
    'field_pdf' => 'field_pdf',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_gender' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_age_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pdf_medical_condition' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pdf' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: PDF Package (field_pdf_package) */
  $handler->display->display_options['relationships']['field_pdf_package_value']['id'] = 'field_pdf_package_value';
  $handler->display->display_options['relationships']['field_pdf_package_value']['table'] = 'field_data_field_pdf_package';
  $handler->display->display_options['relationships']['field_pdf_package_value']['field'] = 'field_pdf_package_value';
  $handler->display->display_options['relationships']['field_pdf_package_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_pdf_package_value']['delta'] = '-1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'BMI';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Gender */
  $handler->display->display_options['fields']['field_gender']['id'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['table'] = 'field_data_field_gender';
  $handler->display->display_options['fields']['field_gender']['field'] = 'field_gender';
  $handler->display->display_options['fields']['field_gender']['relationship'] = 'field_pdf_package_value';
  /* Field: Field collection item: Age type */
  $handler->display->display_options['fields']['field_age_type']['id'] = 'field_age_type';
  $handler->display->display_options['fields']['field_age_type']['table'] = 'field_data_field_age_type';
  $handler->display->display_options['fields']['field_age_type']['field'] = 'field_age_type';
  $handler->display->display_options['fields']['field_age_type']['relationship'] = 'field_pdf_package_value';
  /* Field: Field collection item: Medical Condition */
  $handler->display->display_options['fields']['field_pdf_medical_condition']['id'] = 'field_pdf_medical_condition';
  $handler->display->display_options['fields']['field_pdf_medical_condition']['table'] = 'field_data_field_pdf_medical_condition';
  $handler->display->display_options['fields']['field_pdf_medical_condition']['field'] = 'field_pdf_medical_condition';
  $handler->display->display_options['fields']['field_pdf_medical_condition']['relationship'] = 'field_pdf_package_value';
  $handler->display->display_options['fields']['field_pdf_medical_condition']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Field collection item: PDF */
  $handler->display->display_options['fields']['field_pdf']['id'] = 'field_pdf';
  $handler->display->display_options['fields']['field_pdf']['table'] = 'field_data_field_pdf';
  $handler->display->display_options['fields']['field_pdf']['field'] = 'field_pdf';
  $handler->display->display_options['fields']['field_pdf']['relationship'] = 'field_pdf_package_value';
  $handler->display->display_options['fields']['field_pdf']['click_sort_column'] = 'fid';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'upload_pdf_for_bmi' => 'upload_pdf_for_bmi',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Field: Gender (field_gender) */
  $handler->display->display_options['filters']['field_gender_value']['id'] = 'field_gender_value';
  $handler->display->display_options['filters']['field_gender_value']['table'] = 'field_data_field_gender';
  $handler->display->display_options['filters']['field_gender_value']['field'] = 'field_gender_value';
  $handler->display->display_options['filters']['field_gender_value']['relationship'] = 'field_pdf_package_value';
  $handler->display->display_options['filters']['field_gender_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_gender_value']['group'] = 1;
  /* Filter criterion: Field: Gender (field_gender) */
  $handler->display->display_options['filters']['field_gender_value_1']['id'] = 'field_gender_value_1';
  $handler->display->display_options['filters']['field_gender_value_1']['table'] = 'field_data_field_gender';
  $handler->display->display_options['filters']['field_gender_value_1']['field'] = 'field_gender_value';
  $handler->display->display_options['filters']['field_gender_value_1']['relationship'] = 'field_pdf_package_value';
  $handler->display->display_options['filters']['field_gender_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_gender_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_gender_value_1']['expose']['operator_id'] = 'field_gender_value_1_op';
  $handler->display->display_options['filters']['field_gender_value_1']['expose']['label'] = 'Gender';
  $handler->display->display_options['filters']['field_gender_value_1']['expose']['operator'] = 'field_gender_value_1_op';
  $handler->display->display_options['filters']['field_gender_value_1']['expose']['identifier'] = 'field_gender_value_1';
  $handler->display->display_options['filters']['field_gender_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Field collection item: Age type (field_age_type) */
  $handler->display->display_options['filters']['field_age_type_value']['id'] = 'field_age_type_value';
  $handler->display->display_options['filters']['field_age_type_value']['table'] = 'field_data_field_age_type';
  $handler->display->display_options['filters']['field_age_type_value']['field'] = 'field_age_type_value';
  $handler->display->display_options['filters']['field_age_type_value']['relationship'] = 'field_pdf_package_value';
  $handler->display->display_options['filters']['field_age_type_value']['group'] = 1;
  $handler->display->display_options['filters']['field_age_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_age_type_value']['expose']['operator_id'] = 'field_age_type_value_op';
  $handler->display->display_options['filters']['field_age_type_value']['expose']['label'] = 'Age type';
  $handler->display->display_options['filters']['field_age_type_value']['expose']['operator'] = 'field_age_type_value_op';
  $handler->display->display_options['filters']['field_age_type_value']['expose']['identifier'] = 'field_age_type_value';
  $handler->display->display_options['filters']['field_age_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Field collection item: Medical Condition (field_pdf_medical_condition) */
  $handler->display->display_options['filters']['field_pdf_medical_condition_tid']['id'] = 'field_pdf_medical_condition_tid';
  $handler->display->display_options['filters']['field_pdf_medical_condition_tid']['table'] = 'field_data_field_pdf_medical_condition';
  $handler->display->display_options['filters']['field_pdf_medical_condition_tid']['field'] = 'field_pdf_medical_condition_tid';
  $handler->display->display_options['filters']['field_pdf_medical_condition_tid']['relationship'] = 'field_pdf_package_value';
  $handler->display->display_options['filters']['field_pdf_medical_condition_tid']['value'] = '';
  $handler->display->display_options['filters']['field_pdf_medical_condition_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_pdf_medical_condition_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pdf_medical_condition_tid']['expose']['operator_id'] = 'field_pdf_medical_condition_tid_op';
  $handler->display->display_options['filters']['field_pdf_medical_condition_tid']['expose']['label'] = 'Medical Condition';
  $handler->display->display_options['filters']['field_pdf_medical_condition_tid']['expose']['operator'] = 'field_pdf_medical_condition_tid_op';
  $handler->display->display_options['filters']['field_pdf_medical_condition_tid']['expose']['identifier'] = 'field_pdf_medical_condition_tid';
  $handler->display->display_options['filters']['field_pdf_medical_condition_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_pdf_medical_condition_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_pdf_medical_condition_tid']['vocabulary'] = 'medical_condition';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'BMI';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'uploaded-bmi-list';
  $export['bmi_uploaded_pdf_list'] = $view;

  return $export;
}
