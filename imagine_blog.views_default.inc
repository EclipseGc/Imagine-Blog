<?php
/**
 * @file
 * imagine_blog.views_default.inc
 */

/**
 * Implementation of hook_views_default_views().
 */
function imagine_blog_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'imagine_blog';
  $view->description = 'An Imagine profile specific view override for the default blog output.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Imagine Blog';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Blog Images */
  $handler->display->display_options['fields']['field_blog_images']['id'] = 'field_blog_images';
  $handler->display->display_options['fields']['field_blog_images']['table'] = 'field_data_field_blog_images';
  $handler->display->display_options['fields']['field_blog_images']['field'] = 'field_blog_images';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
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
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog' => 'blog',
  );

  /* Display: Site Blog */
  $handler = $view->new_display('panel_pane', 'Site Blog', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'A site wide aggregate of all blog content by all authors.';
  $handler->display->display_options['pane_title'] = 'Imagine Blog';
  $handler->display->display_options['pane_description'] = 'A site wide aggregate of all blog content by all authors.';
  $handler->display->display_options['pane_category']['name'] = 'Imagine Blog';
  $handler->display->display_options['pane_category']['weight'] = '0';

  /* Display: User Blog Full */
  $handler = $view->new_display('panel_pane', 'User Blog Full', 'panel_pane_2');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['pane_title'] = 'User Blog Full';
  $handler->display->display_options['pane_category']['name'] = 'Imagine Blog';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'context',
      'context' => 'user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'User: Uid',
    ),
  );

  /* Display: Context */
  $handler = $view->new_display('ctools_context', 'Context', 'ctools_context_1');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'ctools_context';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 1;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 1;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['preserve_tags'] = '<ol><ul><li>';
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Field: Content: Blog Images */
  $handler->display->display_options['fields']['field_blog_images']['id'] = 'field_blog_images';
  $handler->display->display_options['fields']['field_blog_images']['table'] = 'field_data_field_blog_images';
  $handler->display->display_options['fields']['field_blog_images']['field'] = 'field_blog_images';
  $handler->display->display_options['fields']['field_blog_images']['label'] = '';
  $handler->display->display_options['fields']['field_blog_images']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_blog_images']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_blog_images']['alter']['text'] = '<div class="blog-image">[field_blog_images]</div>';
  $handler->display->display_options['fields']['field_blog_images']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_blog_images']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_blog_images']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_blog_images']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_blog_images']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_blog_images']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_blog_images']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_blog_images']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_blog_images']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_blog_images']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_blog_images']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_blog_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blog_images']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_blog_images']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_blog_images']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_blog_images']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_blog_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blog_images']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['field_blog_images']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_blog_images']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_blog_images']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_blog_images']['delta_reversed'] = 1;
  $handler->display->display_options['fields']['field_blog_images']['field_api_classes'] = 0;
  /* Field: Content: Blog Category */
  $handler->display->display_options['fields']['field_blog_content']['id'] = 'field_blog_content';
  $handler->display->display_options['fields']['field_blog_content']['table'] = 'field_data_field_blog_content';
  $handler->display->display_options['fields']['field_blog_content']['field'] = 'field_blog_content';
  $handler->display->display_options['fields']['field_blog_content']['label'] = '';
  $handler->display->display_options['fields']['field_blog_content']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_blog_content']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_blog_content']['alter']['text'] = 'in: [field_blog_content]';
  $handler->display->display_options['fields']['field_blog_content']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_blog_content']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_blog_content']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_blog_content']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_blog_content']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_blog_content']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_blog_content']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_blog_content']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_blog_content']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_blog_content']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_blog_content']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_blog_content']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blog_content']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_blog_content']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_blog_content']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_blog_content']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['field_blog_content']['field_api_classes'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'M j, Y';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['name']['alter']['text'] = 'by: [name]';
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Field: Content: Comment count */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = '';
  $handler->display->display_options['fields']['comment_count']['exclude'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '<div class="blog-comment-count">[comment_count]</div>';
  $handler->display->display_options['fields']['comment_count']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['external'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['comment_count']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['comment_count']['alter']['html'] = 0;
  $handler->display->display_options['fields']['comment_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['comment_count']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['comment_count']['empty'] = '0';
  $handler->display->display_options['fields']['comment_count']['hide_empty'] = 0;
  $handler->display->display_options['fields']['comment_count']['empty_zero'] = 0;
  $handler->display->display_options['fields']['comment_count']['hide_alter_empty'] = 0;
  $handler->display->display_options['fields']['comment_count']['format_plural'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="blog-meta-side">[comment_count][created]<br />[name]<br />[field_blog_content]</div>
<div class="blog-details"><h2>[title]</h2>
<div class="blog-body">[field_blog_images][body]</div></div>
';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nothing']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'blog clearfix';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nothing']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Blog Category (field_blog_content) */
  $handler->display->display_options['arguments']['field_blog_content_tid']['id'] = 'field_blog_content_tid';
  $handler->display->display_options['arguments']['field_blog_content_tid']['table'] = 'field_data_field_blog_content';
  $handler->display->display_options['arguments']['field_blog_content_tid']['field'] = 'field_blog_content_tid';
  $handler->display->display_options['arguments']['field_blog_content_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_blog_content_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_blog_content_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_blog_content_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_blog_content_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_blog_content_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_blog_content_tid']['not'] = 0;
  $handler->display->display_options['admin_title'] = 'Blog List Context';
  $handler->display->display_options['argument_input'] = array(
    'field_blog_content_tid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 1,
    ),
  );
  $export['imagine_blog'] = $view;

  return $export;
}
