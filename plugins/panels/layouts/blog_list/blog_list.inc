<?php

/**
 * implementation of hook_panels_layouts()
 */
// Plugin definition
$plugin = array(
  'title' => t('Blog List'),
  'category' => t('Imagine Layouts'),
  'icon' => 'blog_list.png',
  'theme' => 'imagine_blog_blog_list',
  'css' => 'blog_list.css',
  'regions' => array(
    'main' => t('Main Article'),
    'secondary' => t('Secondary Articles'),
    'list' => t('Article List'),
  ),
);
