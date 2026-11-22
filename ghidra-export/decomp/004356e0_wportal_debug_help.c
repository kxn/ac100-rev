// func wportal_debug_help @ 004356e0 size=1

void wportal_debug_help(void)

{
  puts("portal debug commands:");
  puts("wportal_debug_help() -- help menu");
  puts("wportal_debug_enable_nginx_debug_switch()       -- enable nginx debug switch");
  puts("wportal_debug_disable_nginx_debug_switch()      -- disable nginx debug switch");
  puts("wportal_debug_show_nginx_basic_info()           -- show nginx basic infomation");
  puts("wportal_debug_show_nginx_jump_page_entry()      -- show nginx jump page entry");
  puts("wportal_debug_show_nginx_portal_entry()         -- show nginx portal entry");
  puts("wportal_debug_show_nginx_auth_entry()           -- show nginx auth entry");
  puts("wportal_debug_show_nginx_auth_calc_num()        -- show nginx auth entry calc num");
  puts("wportal_debug_show_nginx_all_auth_user_entry()  -- show nginx auth user entry");
  puts("wportal_debug_rdt_traverse_dump()               -- show uac all rdt entry");
  puts("wportal_debug_rdt_ssid_traverse_dump()          -- show rdt for ssid based");
  puts("wportal_debug_vlanlist_for_aut_number()         -- show aut number for every vlan");
  puts("wportal_debug_vlanlist_for_nsa_number()         -- show nsa number for every vlan");
  puts("wportal_debug_vlanlist_for_aut_dump()           -- show uac aut entry for every vlan");
  puts("wportal_debug_vlanlist_for_nsa_dump()           -- show uac nsa entry for every vlan");
  puts("wportal_debug_aut_rbtree_number()               -- show aut number");
  puts("wportal_debug_nsa_rbtree_number()               -- show nsa number");
  puts("wportal_debug_aut_traverse_dump()               -- show all aut");
  puts("wportal_debug_nsa_traverse_dump()               -- show all nsa");
  puts("wportal_debug_username_hash_for_aut_dump()      -- show uac aut entry for every username");
  puts("wportal_debug_username_hash_for_nsa_dump()      -- show uac nsa entry for every username");
  puts("wportal_debug_rds_srv_dump()                    -- show radius server in uac");
  puts("wportal_debug_cmcc_serialno_dump()              -- show cmcc portal serial no rbtree");
  puts("wportal_debug_ftt_traverse_dump()               -- show uac all free strategy entry");
  puts("wportal_debug_sso_notify_config_dump()          -- show sso notify config");
  (*(code *)PTR_puts_00758f90)("wportal_ut_start()                              -- start unit test")
  ;
  return;
}

