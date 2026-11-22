// func _uac_wsta_pkt_set_result_code @ 00634484 size=136

undefined4 _uac_wsta_pkt_set_result_code(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)cw_msg_ele_val_get(param_1,0x21);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0xffffffff;
    if ((g_wsta_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wsta>[error]%s(): %d  -> cw_msg_ele_val_get result code fail.\r\n",
             "_uac_wsta_pkt_set_result_code",0x119);
    }
  }
  else {
    uVar3 = 0;
    if (*piVar1 == 0) {
      *piVar1 = param_2;
    }
  }
  return uVar3;
}

