// func sensor_db_sqlite_notify_msg @ 004d0060 size=260

undefined4 sensor_db_sqlite_notify_msg(undefined4 param_1,void *param_2,size_t param_3)

{
  int iVar1;
  void *__dest;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if (((param_2 != (void *)0x0) && (0 < (int)param_3)) &&
     (iVar1 = FUN_00408450(0x14,0x16c), iVar1 != 0)) {
    *(undefined4 *)(iVar1 + 0xc) = param_1;
    __dest = (void *)FUN_00408450(param_3,0x172);
    *(void **)(iVar1 + 0x10) = __dest;
    if (__dest == (void *)0x0) {
      FUN_00407df0(iVar1);
    }
    else {
      memcpy(__dest,param_2,param_3);
      uVar2 = 0;
      FUN_00407e80("sensor_db_sqlite_notify_msg");
      FUN_004082d0(g_sensor_sql_mutex,0xffffffff);
      g_sensor_sql_option_changed_node_num = g_sensor_sql_option_changed_node_num + 1;
      FUN_004086b0(&g_sensor_msg_list,iVar1);
      FUN_004084b0(g_sensor_msg_cond);
      FUN_00407f30(g_sensor_sql_mutex);
      FUN_004082b0(1,"sensor_db_sqlite_notify_msg");
    }
  }
  return uVar2;
}

