// func _uac_rdmngr_pwr_level_cmp @ 006242ac size=156

bool _uac_rdmngr_pwr_level_cmp(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = true;
  if ((param_1 != 0) && (param_2 != (char *)0x0)) {
    iVar1 = atoi(param_2);
    if (rdmngr_debug_switch == 0) {
      iVar2 = (int)*(char *)(param_1 + 0x19);
    }
    else {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        iVar2 = (int)*(char *)(param_1 + 0x19);
      }
      else {
        printf("[RDMNGR_DEBUG]%s()/%d cur_level:%d,pwr_level:%d\n","_uac_rdmngr_pwr_level_cmp",0x35f
               ,(int)*(char *)(param_1 + 0x19),(int)(char)iVar1);
        iVar2 = (int)*(char *)(param_1 + 0x19);
      }
    }
    bVar3 = iVar2 != (char)iVar1;
  }
  return bVar3;
}

