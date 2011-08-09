<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Blog main'),
  'icon' => 'icon_node.png',
  'description' => t('Extensive display of a blog node.'),
  'required context' => new ctools_context_required(t('Node'), 'node', array('type' => 'blog')),
  'category' => t('Imagine Blog'),
  'defaults' => array('label' => 'title', 'formatter' => '', 'style' => 'thumbnail'),
  'edit form' => array(
    'imagine_blog_blog_main_content_type_formatter_options' => array(
      'default' => TRUE,
      'title' => t('Formatter options for blog image and body'),
    ),
    'imagine_blog_blog_main_content_type_formatter_styles' => t('Formatter Styles'),
  ),
);

/**
 * Render the custom content type.
 */
function imagine_blog_blog_main_content_type_render($subtype, $conf, $panel_args, $context) {
  if (empty($context) || empty($context->data)) {
    return;
  }

  // Get a shortcut to the node.
  $node = $context->data;
  if (empty($conf['label']) || $conf['label'] == 'title') {
    $label = 'hidden';
    $conf['label'] = 'title';
  }
  else {
    $label = $conf['label'];
  }

  $field_settings = array(
    'label' => $label,
    'type' => $conf['formatter'],
  );

  $block = new stdClass();
  $block->module  = 'imagine_blog';
  $block->title   = '';
  $block->content = theme('imagine_blog_main_blog', array('node' => $node, 'style' => $conf['style'], 'field_settings' => $field_settings));
  $block->delta   = $node->nid;

  return $block;
}

/**
 * Returns an edit form for custom type settings.
 */
function imagine_blog_blog_main_content_type_formatter_options($form, &$form_state) {
  $conf = $form_state['conf'];
  $styles = image_styles();
  $options = array();
  foreach ($styles as $key => $style) {
    $options[$key] = $style['name'];
  }

  $form['style'] = array(
    '#title' => t('Image Style'),
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => $conf['style'],
  );

  $field = field_info_field('body');
  module_load_include('inc', 'field_ui', 'field_ui.admin');
  $formatter_options = field_ui_formatter_options($field['type']);

  $field_label_options = array(
    'title' => t('Pane title'),
    'above' => t('Above'),
    'inline' => t('Inline'),
    'hidden' => t('Hidden'),
  );

  $form['label'] = array(
    '#type' => 'select',
    '#title' => t('Label'),
    '#options' => $field_label_options,
    '#default_value' => $conf['label'],
  );

  $form['formatter'] = array(
    '#type' => 'select',
    '#title' => t('Select a formatter'),
    '#options' => $formatter_options,
    '#default_value' => $conf['formatter'],
  );
  return $form;
}

/**
 * Submit handler for the custom type settings form.
 */
function imagine_blog_blog_main_content_type_formatter_options_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 *
 */
function imagine_blog_blog_main_content_type_formatter_styles($form, &$form_state) {
  if (!$form_state['conf']['formatter_settings']) {
    $form_state['conf']['formatter_settings'] = array();
  }
  $conf = $form_state['conf'];
  $field = field_info_field('body');
  module_load_include('inc', 'field_ui', 'field_ui.admin');

  ctools_include('fields');
  $form['ctools_field_list'] = array(
    '#type' => 'value',
    '#value' => array(),
  );

  ctools_fields_get_field_formatter_settings_form($field, $conf['formatter'], $form, $form_state);
  return $form;
}

/**
 * Returns the administrative title for a type.
 */
function imagine_blog_blog_main_content_type_admin_title($subtype, $conf, $context) {
  return t('"@s" Main Blog style formatting.', array('@s' => $context->identifier));
}
