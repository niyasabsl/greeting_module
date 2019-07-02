<?php

/**
 * @file
 * greeting_custom_content_type.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function greeting_custom_content_type_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'greeting_image'.
  $field_bases['greeting_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'greeting_image',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'label' => 'Greeting image',
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  return $field_bases;
}
