<?php
/**
 * @file
 * upload_pdf_for_bmi.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function upload_pdf_for_bmi_taxonomy_default_vocabularies() {
  return array(
    'medical_condition' => array(
      'name' => 'Medical Condition',
      'machine_name' => 'medical_condition',
      'description' => 'Medical Condition',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
