// func _mesh_tmp_re_roam_timer_timeout @ 004c1018 size=164

void _mesh_tmp_re_roam_timer_timeout(undefined2 *param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 local_10;
  int local_c;
  
  local_c = 0;
  if (param_1 != (undefined2 *)0x0) {
    uVar1 = *param_1;
    iVar2 = mesh_db_re_auto_switch_get(&local_c);
    if (iVar2 == 0) {
      if (local_c == 0) {
        local_10 = 0;
        mesh_db_ap_entry_child_foreach_proc(uVar1,1,_mesh_tmp_re_roam_pkt_send,&local_10);
      }
      mesh_db_ap_entry_tmp_re_roam_timer_op(uVar1,0,0,1);
    }
    else if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Failed to join for formal callback return failed result code.\n",
             "_mesh_tmp_re_roam_timer_timeout",0xbe);
    }
  }
  return;
}

