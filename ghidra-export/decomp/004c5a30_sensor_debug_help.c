// func sensor_debug_help @ 004c5a30 size=1

void sensor_debug_help(void)

{
  puts("sensor module help:");
  puts("sensor_err_switch                 -- error switch.");
  puts("sensor_warning_switch             -- warning switch.");
  puts("sensor_debug_switch               -- debug switch.");
  puts("sensor_di_err_switch              -- error switch.");
  puts("sensor_di_warning_switch          -- warning switch.");
  puts("sensor_di_debug_switch            -- debug switch.");
  puts("sensor_test_err_switch            -- error switch.");
  puts("sensor_test_warning_switch        -- warning switch.");
  puts("sensor_test_debug_switch          -- debug  switch.");
  puts("g_sensor_state                    -- sensor FSM state.");
  puts("g_backhaul_wserv_id               -- backhaul wservice ID.");
  puts("sensor_db_entry_dump(detail)      -- dump sensor list.");
  puts("sensor_db_entry_dump_by_id(id)    -- dump sensor info by sensor ID.");
  puts("sensor_mngt_global_dump()         -- dump global sensor mngt info.");
  puts("wips_info_list_dump()             -- wips_info_list_dump.");
  puts("wips_whitelist_dump()             -- wips_whitelist_dump.");
  puts("wips_detection_dev_dump()         -- wips_detection_dev_dump.");
  puts("sensor_di_setting_dump()          -- dump deep_inspection setting");
  puts("sensor_test_case_dump()           -- dump sensor_test case");
  puts("sensor_test_bssid_alloc_table_dump()   --dump sensor_test bssid_alloc_table");
  (*(code *)PTR_puts_00758f90)
            ("sensor_test_simple_result_dump()       --dump sensor_test simple result");
  return;
}

