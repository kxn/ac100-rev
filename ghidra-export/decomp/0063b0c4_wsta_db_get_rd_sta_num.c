// func wsta_db_get_rd_sta_num @ 0063b0c4 size=736

int wsta_db_get_rd_sta_num(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *__format;
  undefined4 uVar7;
  undefined1 auStack_68 [56];
  int local_30;
  int local_2c;
  
  param_2 = param_2 & 0xff;
  memset(auStack_68,0,0x38);
  if (((int)param_1 < 0) || (iVar2 = apmngr_db_get_ap_max(), iVar2 <= (int)param_1)) {
    if ((g_wsta_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      __format = "<wsta>[warning]%s(): %d  -> invalid ap_id[%d]!\r\n";
      uVar7 = 0xb5c;
      param_2 = param_1;
      goto LAB_0063b1c8;
    }
  }
  else {
    if ((param_2 != 0) && (uVar3 = rdmngr_profile_get_max_rd_per_ap(), param_2 <= uVar3)) {
      FUN_004082d0(DAT_007cc6bc,0xffffffff);
      uVar3 = 1;
      iVar2 = 0;
      local_30 = param_1 << 2;
      local_2c = (param_2 - 1) * 4;
      do {
        uVar4 = rdmngr_profile_get_max_wlan_per_rd();
        if (uVar4 < uVar3) {
          FUN_00407f30(DAT_007cc6bc);
          return iVar2;
        }
        iVar5 = FUN_004081b0(*(int *)(*(int *)(DAT_007cc6e4 + local_30) + local_2c) +
                             (uVar3 - 1) * 0xc);
        while (iVar1 = iVar5, iVar1 != 0) {
          iVar5 = FUN_00408680(iVar1);
          iVar6 = wsta_db_get_mac_entry_by_mld(iVar1 + 0x68,auStack_68);
          if (iVar6 == 0) {
            iVar6 = wsta_db_get_mac_entry_by_peer(iVar1 + 0x68,auStack_68);
            if (iVar6 == 0) {
              if ((g_wsta_debug == 0) || (iVar6 = is_target_debug_ap(), iVar6 == 0))
              goto LAB_0063b2ac;
              printf("<wsta>[debug]%s(): %d  -> %02X-%02X-%02X-%02X-%02X-%02X is mld mac and peer mac!\r\n"
                     ,"wsta_db_get_rd_sta_num",0xb73,(uint)*(byte *)(iVar1 + 0x68),
                     (uint)*(byte *)(iVar1 + 0x69),(uint)*(byte *)(iVar1 + 0x6a),
                     (uint)*(byte *)(iVar1 + 0x6b),(uint)*(byte *)(iVar1 + 0x6c),
                     (uint)*(byte *)(iVar1 + 0x6d));
              iVar2 = iVar2 + 1;
            }
            else if ((g_wsta_debug != 0) && (iVar6 = is_target_debug_ap(), iVar6 != 0)) {
              printf("<wsta>[debug]%s(): %d  -> %02X-%02X-%02X-%02X-%02X-%02X is mld mac!\r\n",
                     "wsta_db_get_rd_sta_num",0xb79,(uint)*(byte *)(iVar1 + 0x68),
                     (uint)*(byte *)(iVar1 + 0x69),(uint)*(byte *)(iVar1 + 0x6a),
                     (uint)*(byte *)(iVar1 + 0x6b),(uint)*(byte *)(iVar1 + 0x6c),
                     (uint)*(byte *)(iVar1 + 0x6d));
            }
          }
          else {
LAB_0063b2ac:
            iVar2 = iVar2 + 1;
          }
        }
        uVar3 = uVar3 + 1 & 0xff;
      } while( true );
    }
    if (g_wsta_warning != 0) {
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return -1;
      }
      __format = "<wsta>[warning]%s(): %d  -> invalid rd_id[%d]!\r\n";
      uVar7 = 0xb61;
LAB_0063b1c8:
      printf(__format,"wsta_db_get_rd_sta_num",uVar7,param_2);
      return -1;
    }
  }
  return -1;
}

