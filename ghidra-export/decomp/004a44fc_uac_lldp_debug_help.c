// func uac_lldp_debug_help @ 004a44fc size=1

void uac_lldp_debug_help(void)

{
  puts("uac_lldp_err_switch     = 1/0                    -- enable/disable <error> level message");
  puts("uac_lldp_debug_switch   = 1/0                    -- enable/disable <debug> level message");
  (*(code *)PTR_puts_00758f90)
            ("uac_lldp_global_config_show()                 -- show uac_lldp global configuration");
  return;
}

