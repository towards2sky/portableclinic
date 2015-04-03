<?php
/**
 * @file
 * patient_assessment_form.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function patient_assessment_form_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_bmi|node|patient_assessment_form|form';
  $field_group->group_name = 'group_bmi';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'patient_assessment_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'BMI',
    'weight' => '2',
    'children' => array(
      0 => 'field_bmi',
      1 => 'field_height_m',
      2 => 'field_weight_kg',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_bmi|node|patient_assessment_form|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_daily_eating_pattern|node|patient_assessment_form|form';
  $field_group->group_name = 'group_daily_eating_pattern';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'patient_assessment_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Daily Eating Pattern',
    'weight' => '3',
    'children' => array(
      0 => 'field_breakfast',
      1 => 'field_first_thing_in_the_morning',
      2 => 'field_fruit_juices',
      3 => 'field_raw_food',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_daily_eating_pattern|node|patient_assessment_form|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dinner|node|patient_assessment_form|form';
  $field_group->group_name = 'group_dinner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'patient_assessment_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dinner',
    'weight' => '5',
    'children' => array(
      0 => 'field_fruit_juices_dinner',
      1 => 'field_non_vegetarian_dinner',
      2 => 'field_raw_food_dinner',
      3 => 'field_snacks',
      4 => 'field_vegetarian_mention',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_dinner|node|patient_assessment_form|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_lunch|node|patient_assessment_form|form';
  $field_group->group_name = 'group_lunch';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'patient_assessment_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Lunch',
    'weight' => '4',
    'children' => array(
      0 => 'field_non_vegetarian_mention_the',
      1 => 'field_vegetarian_mention_the_amo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_lunch|node|patient_assessment_form|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_medication|node|patient_assessment_form|form';
  $field_group->group_name = 'group_medication';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'patient_assessment_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Medication',
    'weight' => '7',
    'children' => array(
      0 => 'field_are_you_currently_taking_a',
      1 => 'field_family_history_is_any_one_',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_medication|node|patient_assessment_form|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_persional_info|node|patient_assessment_form|form';
  $field_group->group_name = 'group_persional_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'patient_assessment_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Persional Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_blood_pressure_diastolic',
      1 => 'field_blood_pressure_systolic',
      2 => 'field_dob',
      3 => 'field_gender',
      4 => 'field_medical_condition',
      5 => 'field_mobile',
      6 => 'field_patient_email',
      7 => 'field_profession',
      8 => 'field_pulse_rate',
      9 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_persional_info|node|patient_assessment_form|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_physical_activity|node|patient_assessment_form|form';
  $field_group->group_name = 'group_physical_activity';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'patient_assessment_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Physical Activity',
    'weight' => '6',
    'children' => array(
      0 => 'field_mention_the_level_of_physi',
      1 => 'field_sleep_pattern',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_physical_activity|node|patient_assessment_form|form'] = $field_group;

  return $export;
}
