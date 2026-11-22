// func _mesh_tmp_re_roam_pkt_send @ 004c3790 size=104

undefined4 _mesh_tmp_re_roam_pkt_send(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 1;
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Invalid input\n","_mesh_tmp_re_roam_pkt_send",0xa7);
    }
  }
  else {
    uVar1 = 0;
    mesh_pkt_auto_switch_request_send(*(undefined2 *)(param_1 + 0xc),*param_2,1);
  }
  return uVar1;
}

