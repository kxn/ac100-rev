// func cloud_mngt_debug_help @ 0049c278 size=1

void cloud_mngt_debug_help(void)

{
  puts("cloud_mngt_err_switch     = 1/0                    -- enable/disable <error> level message")
  ;
  puts("cloud_mngt_debug_switch   = 1/0                    -- enable/disable <debug> level message")
  ;
  (*(code *)PTR_puts_00758f90)
            (
            "cloud_mngt_global_config_show()                 -- show cloud mngt global configuration"
            );
  return;
}

