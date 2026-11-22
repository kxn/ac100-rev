// func _mesh_pkt_discover_req_listen @ 004c0914 size=232

undefined4 _mesh_pkt_discover_req_listen(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 local_38 [2];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  uVar2 = 0;
  iVar1 = cw_msg_ele_priv_val_get_from_pkt(param_1,0x76);
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_38[0] = 0;
  if (iVar1 != 0) {
    iVar1 = cw_priv_mesh_private_control_get(iVar1,0x11);
    if (iVar1 != 0) {
      uVar2 = 0xffffffff;
      FUN_0051ad88(&local_34);
      FUN_0051ad88(&local_20);
      local_38[0] = 0;
      iVar1 = cw_priv_mesh_private_control_add(&local_34,0x11,local_38);
      if (iVar1 == 0) {
        iVar1 = cw_service_msg_add(param_3,0x25,&local_28,1,0x76,&local_34);
        if (iVar1 == 0) {
          uVar2 = 0;
          cw_priv_mesh_private_control_sub_ele_free(&local_34);
        }
        else {
          cw_priv_mesh_private_control_sub_ele_free(&local_34);
        }
      }
    }
  }
  return uVar2;
}

