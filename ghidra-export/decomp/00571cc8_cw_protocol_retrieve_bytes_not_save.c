// func cw_protocol_retrieve_bytes_not_save @ 00571cc8 size=152

uint cw_protocol_retrieve_bytes_not_save(int *param_1,ushort param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)param_2;
  if ((((param_1 == (int *)0x0) || (*param_1 == 0)) || (uVar2 == 0)) ||
     ((int)((uint)*(ushort *)(param_1 + 1) - (uint)*(ushort *)((int)param_1 + 6)) < (int)uVar2)) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n","cw_protocol_retrieve_bytes_not_save"
             ,0xeb);
    }
  }
  else {
    *(ushort *)((int)param_1 + 6) = param_2 + *(ushort *)((int)param_1 + 6);
  }
  return uVar2;
}

