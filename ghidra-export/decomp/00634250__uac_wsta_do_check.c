// func _uac_wsta_do_check @ 00634250 size=564

int _uac_wsta_do_check(undefined4 param_1,uint param_2,undefined4 param_3,void *param_4,
                      undefined1 param_5)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 local_258;
  undefined1 local_257;
  undefined4 local_254;
  undefined1 auStack_250 [2];
  undefined1 local_24e;
  undefined1 auStack_24c [28];
  undefined1 auStack_230 [283];
  int local_115;
  
  memset(auStack_230,0,0x205);
  iVar4 = 0;
  if (DAT_007cca9c != 0) {
    if ((param_2 == 0) || (uVar1 = rdmngr_profile_get_max_rd_per_ap(), uVar1 < param_2)) {
      iVar4 = 0x25;
      if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("<wserv>[error]%s(): %d  -> invalid ap id[%d],radio_id[%d],wlan id[%d]!\r\n",
               "_uac_wsta_do_check",0x6a,param_1,param_2,param_3);
      }
    }
    else {
      memset(&local_258,0,0x28);
      local_258 = (undefined1)param_2;
      local_257 = (undefined1)param_3;
      iVar5 = 0x25;
      local_24e = param_5;
      local_254 = param_1;
      memcpy(auStack_24c,param_4,6);
      uVar2 = rdmngr_db_generate_rd_id(param_1,param_2);
      iVar3 = wserv_db_rd_get_wserv_id(uVar2,param_3);
      iVar4 = iVar5;
      if ((((iVar3 != -1) && (iVar3 = wserv_db_get_entry_by_id(iVar3,auStack_230), iVar3 == 0)) &&
          (iVar4 = 0x25, local_115 != 0)) &&
         (iVar3 = uac_wservice_get_vlan(param_1,param_2,param_3,auStack_250), iVar4 = iVar5,
         iVar3 == 0)) {
        for (iVar4 = FUN_004081b0(&l_wsta_assoc_check_reg); iVar4 != 0; iVar4 = FUN_00408680(iVar4))
        {
          if (*(int **)(iVar4 + 0x34) == (int *)0x0) {
            iVar3 = 0;
          }
          else {
            iVar3 = **(int **)(iVar4 + 0x34);
            if (iVar3 == 0) {
              iVar3 = 0;
            }
          }
          iVar3 = (**(code **)(iVar4 + 0x30))(&local_258,iVar3);
          if (iVar3 != 0) {
            if (g_wsta_warning == 0) {
              return iVar3;
            }
            iVar5 = is_target_debug_ap();
            if (iVar5 == 0) {
              return iVar3;
            }
            printf("<wsta>[warning]%s(): %d  -> _uac_wsta_do_check() fail, reg[%s].\r\n",
                   "_uac_wsta_do_check",0x89,iVar4 + 0xc);
            return iVar3;
          }
        }
        iVar4 = 0;
      }
    }
  }
  return iVar4;
}

