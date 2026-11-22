// func whitelist_entry_delete @ 004caf98 size=112

undefined4 whitelist_entry_delete(int param_1)

{
  sensor_db_sqlite_notify_msg(4,param_1 + 0xc,4);
  wips_whitelist_send(*(undefined4 *)(param_1 + 0xc),0xffff,2);
  wips_update_due_to_whitelist(param_1,0);
  FUN_004080f0(g_whitelist_id_allocator,*(undefined4 *)(param_1 + 0xc));
  FUN_00408500(param_1);
  FUN_00407df0(param_1);
  return 0;
}

