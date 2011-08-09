<?php
/**
 * @file
 * imagine_blog.pages_default.inc
 */

/**
 * Implementation of hook_default_page_manager_handlers().
 */
function imagine_blog_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'blog_panel_context';
  $handler->task = 'blog';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Blogs',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Blog List Context',
        'keyword' => 'view',
        'name' => 'view:imagine_blog-ctools_context_1',
        'id' => 1,
      ),
    ),
    'relationships' => array(
      0 => array(
        'identifier' => 'Blog 1 from View',
        'keyword' => 'node1',
        'name' => 'node_from_view',
        'context' => 'context_view:imagine_blog-ctools_context_1_1',
        'row' => '1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Blog 2 from View',
        'keyword' => 'node2',
        'name' => 'node_from_view',
        'context' => 'context_view:imagine_blog-ctools_context_1_1',
        'row' => '2',
        'id' => 2,
      ),
      2 => array(
        'identifier' => 'Blog 3 from View',
        'keyword' => 'node3',
        'name' => 'node_from_view',
        'context' => 'context_view:imagine_blog-ctools_context_1_1',
        'row' => '3',
        'id' => 3,
      ),
    ),
  );
  $display = new panels_display;
  $display->layout = 'blog_list';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'main' => NULL,
      'secondary' => NULL,
      'list' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'list';
    $pane->type = 'views_row';
    $pane->subtype = 'views_row';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'rows' => array(
        4 => '4',
        5 => '5',
        6 => '6',
        7 => '7',
        8 => '8',
        9 => '9',
        10 => '10',
      ),
      'use_fields' => 0,
      'fields' => array(),
      'context' => 'context_view:imagine_blog-ctools_context_1_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['list'][0] = 'new-1';
    $pane = new stdClass;
    $pane->pid = 'new-2';
    $pane->panel = 'list';
    $pane->type = 'views_pager';
    $pane->subtype = 'views_pager';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'context_view:imagine_blog-ctools_context_1_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-2'] = $pane;
    $display->panels['list'][1] = 'new-2';
    $pane = new stdClass;
    $pane->pid = 'new-3';
    $pane->panel = 'main';
    $pane->type = 'blog_main';
    $pane->subtype = 'blog_main';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => NULL,
      'context' => 'relationship_node_from_view_1',
      'override_title' => 1,
      'override_title_text' => '',
      'label' => 'hidden',
      'formatter' => 'text_trimmed',
      'style' => 'medium',
      'formatter_settings' => array(),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-3'] = $pane;
    $display->panels['main'][0] = 'new-3';
    $pane = new stdClass;
    $pane->pid = 'new-4';
    $pane->panel = 'secondary';
    $pane->type = 'blog_main';
    $pane->subtype = 'blog_main';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_trimmed',
      'style' => 'thumbnail',
      'context' => 'relationship_node_from_view_2',
      'override_title' => 0,
      'override_title_text' => '',
      'formatter_settings' => array(),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-4'] = $pane;
    $display->panels['secondary'][0] = 'new-4';
    $pane = new stdClass;
    $pane->pid = 'new-5';
    $pane->panel = 'secondary';
    $pane->type = 'blog_main';
    $pane->subtype = 'blog_main';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_trimmed',
      'style' => 'thumbnail',
      'context' => 'relationship_node_from_view_3',
      'override_title' => 0,
      'override_title_text' => '',
      'formatter_settings' => array(),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $display->content['new-5'] = $pane;
    $display->panels['secondary'][1] = 'new-5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['blog_panel_context'] = $handler;

  return $export;
}

/**
 * Implementation of hook_default_page_manager_pages().
 */
function imagine_blog_default_page_manager_pages() {
  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'imagine_user_blog';
  $page->task = 'page';
  $page->admin_title = 'Imagine User Blog';
  $page->admin_description = 'The dynamic page which contains all images for a particular user.';
  $page->path = 'user/%user/blog/view';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 4,
          ),
        ),
        'context' => 'argument_entity_id:user_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'default tab',
    'title' => 'View',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'tab',
      'title' => 'Blog',
      'name' => 'navigation',
      'weight' => '5',
    ),
  );
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'User: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_imagine_user_blog_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'imagine_user_blog';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'User Gallery',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display;
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%user:name\'s Blog';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass;
    $pane->pid = 'new-1';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'imagine_blog-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:user_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $display->content['new-1'] = $pane;
    $display->panels['middle'][0] = 'new-1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['imagine_user_blog'] = $page;

  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'imagine_user_blog_add';
  $page->task = 'page';
  $page->admin_title = 'Imagine User Blog Add';
  $page->admin_description = 'Creates a menu item allowing user to create new images from their user pages.';
  $page->path = 'user/%user/blog/add_blog';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 4,
          ),
        ),
        'context' => 'argument_entity_id:user_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:user_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'action',
    'title' => 'Add Blog Article',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'User: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => TRUE,
  );
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_imagine_user_blog_add_menu_context';
  $handler->task = 'page';
  $handler->subtask = 'imagine_user_blog_add';
  $handler->handler = 'menu_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Guild Members',
    'no_blocks' => FALSE,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 4,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'administer nodes',
          ),
          'context' => 'argument_entity_id:user_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
    'context_admin_options' => 'node_create_pubopt',
    'submitted_context' => NULL,
    'node_types' => 'blog',
    'publishing_options' => 'published',
  );
  $page->default_handlers[$handler->name] = $handler;
  $pages['imagine_user_blog_add'] = $page;

  $page = new stdClass;
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'imagine_user_blog_add_root';
  $page->task = 'page';
  $page->admin_title = 'Imagine User Blog Add Root';
  $page->admin_description = 'Creates a menu item allowing user to create new images from their user pages.';
  $page->path = 'user/%user/add_blog';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 4,
          ),
        ),
        'context' => 'argument_entity_id:user_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:user_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'action',
    'title' => 'Add Blog Article',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'User: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => TRUE,
  );
  $page->default_handlers = array();
  $handler = new stdClass;
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_imagine_user_blog_add_root_menu_context';
  $handler->task = 'page';
  $handler->subtask = 'imagine_user_blog_add_root';
  $handler->handler = 'menu_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Guild Members',
    'no_blocks' => FALSE,
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 4,
            ),
          ),
          'context' => 'argument_entity_id:user_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'administer nodes',
          ),
          'context' => 'argument_entity_id:user_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
    'context_admin_options' => 'node_create_pubopt',
    'submitted_context' => NULL,
    'node_types' => 'blog',
    'publishing_options' => 'published',
  );
  $page->default_handlers[$handler->name] = $handler;
  $pages['imagine_user_blog_add_root'] = $page;

 return $pages;

}
