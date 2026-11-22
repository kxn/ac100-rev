// func _wserv_db_ap_sync @ 005f0f7c size=168

undefined4 _wserv_db_ap_sync(int param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = *param_2;
  iVar2 = wserv_db_ap_sync_bind_list
                    ((uint)uVar1,*(undefined2 *)(param_1 + 0xc),*(undefined4 *)(param_2 + 2),
                     *(undefined4 *)(param_2 + 4),*(undefined4 *)(param_2 + 6),
                     *(undefined4 *)(param_2 + 8));
  if (((iVar2 != 0) && (g_wserv_error != 0)) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("<wserv>[warning]%s(): %d  -> sync bind list from %d to %d failed\r\n",
           "_wserv_db_ap_sync",0x1066,(uint)uVar1,(uint)*(ushort *)(param_1 + 0xc));
  }
  return 0;
}

