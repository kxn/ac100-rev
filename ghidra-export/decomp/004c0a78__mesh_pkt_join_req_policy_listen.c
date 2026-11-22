// func _mesh_pkt_join_req_policy_listen @ 004c0a78 size=304

undefined4
_mesh_pkt_join_req_policy_listen(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined1 auStack_2e8 [16];
  ushort local_2d8;
  
  memset(auStack_2e8,0,0x2d8);
  iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x76);
  piVar2 = (int *)cw_msg_ele_val_get(param_3,0x21);
  if ((piVar2 == (int *)0x0) || (*piVar2 == 0)) {
    iVar3 = apmngr_db_entry_get_by_mac(param_2,auStack_2e8);
    uVar5 = 0;
    if ((iVar3 == 0) &&
       ((uVar5 = 0, iVar1 != 0 &&
        (puVar4 = (undefined4 *)cw_priv_mesh_private_control_get(iVar1,0x1b),
        puVar4 != (undefined4 *)0x0)))) {
      if (mesh_debug_switch != '\0') {
        printf("[MESH_DEBUG]%s()/%d get AP(%d) policy_mask: %d policy: %d\n",
               "_mesh_pkt_join_req_policy_listen",0x124,(uint)local_2d8,*puVar4,puVar4[1]);
      }
      uVar5 = 0;
      mesh_db_ap_entry_policy_set(local_2d8,*puVar4,puVar4[1]);
    }
  }
  else {
    uVar5 = 0xffffffff;
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d Failed to join for formal callback return failed result code.\n",
             "_mesh_pkt_join_req_policy_listen",0x11c);
    }
  }
  return uVar5;
}

