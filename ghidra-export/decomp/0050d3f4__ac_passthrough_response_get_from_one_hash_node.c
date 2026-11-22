// func _ac_passthrough_response_get_from_one_hash_node @ 0050d3f4 size=148

void _ac_passthrough_response_get_from_one_hash_node(int param_1,int *param_2)

{
  int iVar1;
  
  if (((param_1 == 0) || (param_2 == (int *)0x0)) || (*param_2 != 0)) {
    if (ac_passthrough_err_switch != '\0') {
      printf("[AC_PASSTHROUGH_ERROR]%s()/%d  Get hash node error\n\n",
             "_ac_passthrough_response_get_from_one_hash_node",0x538);
      return;
    }
  }
  else {
    iVar1 = _ac_passthrough_response_get_from_one_ap
                      (param_1,param_2[1],param_2[2],param_2 + 5,param_2 + 3);
    *param_2 = iVar1;
    if (iVar1 == 0) {
      param_2[4] = param_2[4] + 1;
    }
  }
  return;
}

