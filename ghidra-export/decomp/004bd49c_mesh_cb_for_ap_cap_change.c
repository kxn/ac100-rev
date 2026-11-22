// func mesh_cb_for_ap_cap_change @ 004bd49c size=244

undefined4 mesh_cb_for_ap_cap_change(short param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_28;
  undefined2 local_24;
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  
  uVar1 = 0xffffffff;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_28 = 0;
  local_24 = 0;
  if (((param_2 != 0) &&
      ((((iVar2 = *(int *)(param_2 + 0x14), iVar2 == 4 || (iVar2 == 8)) || (iVar2 == 6)) ||
       (uVar1 = 0, iVar2 == 5)))) && (uVar1 = 0, *(short *)(param_2 + 0x18) != -1)) {
    mesh_db_ap_entry_delete(*(undefined2 *)(param_2 + 0x10));
    local_1c = local_1c & 0xffffff;
    local_20 = CONCAT22(*(undefined2 *)(param_2 + 0x18),*(undefined2 *)(param_2 + 0x18));
    mesh_db_ap_entry_add(*(undefined2 *)(param_2 + 0x10),0,&local_20,0);
    memcpy(&local_28,(void *)(param_2 + 0x48),6);
    if (param_1 != -1) {
      mesh_pkt_re_operation_request_send(param_1,1,&local_28,3);
    }
    mesh_pkt_re_operation_request_send((int)*(short *)(param_2 + 0x18),1,&local_28,2);
    uVar1 = 0;
  }
  return uVar1;
}

