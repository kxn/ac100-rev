// func rrm_debug_help @ 004af78c size=1

void rrm_debug_help(void)

{
  puts("rrm module help:");
  puts("rrm_err_switch                 -- error switch.");
  puts("rrm_warning_switch             -- warning switch.");
  puts("rrm_debug_switch               -- debug switch.");
  puts("rrm_pkt_dump_switch            -- rrm packet dump switch.");
  puts("rrm_info_dump_switch           -- rrm collected information dump switch.");
  puts("rrm_pwr_max_neigh_size         -- rrm_pwr_max_neigh_size.");
  puts("rrm_pwr_tpc_neigh_size         -- rrm_pwr_tpc_neigh_size.");
  puts("rrm_pwr_min_power              -- rrm_pwr_min_power.");
  puts("rrm_pwr_max_power              -- rrm_pwr_max_power.");
  puts("rrm_pwr_smooth_tpc_switch      -- rrm_pwr_smooth_tpc_switch.");
  puts("pwr_rrm_max_change_power       -- pwr_rrm_max_change_power.");
  puts("pwr_rrm_max_count              -- pwr_rrm_max_count.");
  puts("high_threshold                 -- rrm high thresold.");
  puts("low_threshold                  -- rrm low thresold.\n");
  puts("rrm_rssi_threshold_set()       -- set rssi threshold.");
  puts("rrm_group_id_set()             -- set groups id.");
  puts("rrm_group_id_unset()           -- unset groups id.");
  puts("rrm_ap_collect_info_set(...)   -- set ap collect info,0 means unset.");
  puts("rrm_global_config_dump()       -- global config info.");
  (*(code *)PTR_puts_00758f90)("rrm_info_dump()                -- rrm info.");
  return;
}

