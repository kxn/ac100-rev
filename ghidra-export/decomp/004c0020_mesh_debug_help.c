// func mesh_debug_help @ 004c0020 size=1

void mesh_debug_help(void)

{
  puts("mesh module help:");
  puts("mesh_err_switch                 -- error switch.");
  puts("mesh_warning_switch             -- warning switch.");
  puts("mesh_debug_switch               -- debug switch.");
  puts("mesh_pkt_dump_switch            -- mesh packet dump switch.");
  puts(
      "mesh_db_global_config_dump      -- dump global config,including backhual info and web password."
      );
  puts("mesh_db_discover_entry_dump_all -- dump discover device entry list.");
  puts("mesh_db_ap_entry_dump_all       -- dump ap entry list,including topology info.");
  puts("mesh_db_single_ap_entry_dump    -- dump target ap entry info,including topology info.");
  (*(code *)PTR_puts_00758f90)
            (
            "mesh_db_single_ap_entry_parent_dump    -- dump target ap entry\'s parent(s) info,including topology info."
            );
  return;
}

