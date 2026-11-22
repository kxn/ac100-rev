// func apmngr_debug_help_print @ 00533748 size=100

void apmngr_debug_help_print(void)

{
  puts("apmngr_err_switch     = 1/0                        -- enable/disable <error> level message")
  ;
  puts(
      "apmngr_warning_switch = 1/0                        -- enable/disable <warning> level message"
      );
  puts("apmngr_debug_switch   = 1/0                        -- enable/disable <debug> level message")
  ;
  puts(
      "apmngr_pkt_switch     = 1/0                        -- enable/disable <packet> packet details"
      );
  puts("apmngr_global_config_show()                        -- show apmgr global configuration");
  puts(
      "apmngr_debug_ap_add(str model, int num, int firm)  -- utility function, add some simulate AP for debug"
      );
  puts("apmngr_debug_telnet_config(enable, telnet_port)    -- telnet config test");
  return;
}

