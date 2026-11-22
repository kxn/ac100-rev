// func mesh_switch_send @ 004c31b0 size=136

undefined4 mesh_switch_send(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0xffffffff;
  if (param_1 != 0) {
    iVar3 = ap_mesh_switch_is_enable(*(undefined2 *)(param_1 + 0x10));
    if (mesh_debug_switch == '\0') {
      uVar1 = *(undefined2 *)(param_1 + 0x10);
    }
    else {
      printf("[MESH_DEBUG]%s()/%d ap(%u) role %d enable %d.\n","mesh_switch_send",0x72c,
             (uint)*(ushort *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),(uint)(iVar3 != 0));
      uVar1 = *(undefined2 *)(param_1 + 0x10);
    }
    mesh_pkt_enable_request_send(uVar1,(uint)(iVar3 != 0));
    uVar2 = 0;
  }
  return uVar2;
}

