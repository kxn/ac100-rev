// func wserv_db_for_each_l3_ap_unbind_vlan @ 005f2b1c size=1104

undefined4 wserv_db_for_each_l3_ap_unbind_vlan(uint param_1,code *param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *__format;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  byte *pbVar10;
  uint uVar11;
  byte *__s;
  uint auStack_320 [2];
  byte abStack_318 [8];
  int local_310;
  int local_30c;
  int local_308;
  undefined1 auStack_300 [28];
  int local_2e4;
  
  local_310 = 0;
  local_30c = 0;
  local_308 = 0;
  iVar2 = apmngr_db_get_ap_max();
  iVar3 = apmngr_db_get_template_max();
  iVar4 = apmngr_db_get_sensor_max();
  iVar2 = -(iVar2 + iVar3 + iVar4 + 0xeU & 0xfffffff8);
  __s = abStack_318 + iVar2;
  if (param_1 < 0x1001) {
    uVar8 = 0;
    if (param_2 != (code *)0x0) {
      iVar3 = apmngr_db_get_ap_max();
      iVar4 = apmngr_db_get_template_max();
      iVar5 = apmngr_db_get_sensor_max();
      iVar3 = wserv_calloc(iVar3 + iVar4 + iVar5,4);
      if (iVar3 == 0) {
        if (g_wserv_error == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        __format = "<wserv>[warning]%s(): %d  -> no memory!\r\n";
        uVar7 = 0x13d3;
      }
      else {
        local_310 = 0;
        iVar4 = apmngr_db_get_ap_max();
        iVar5 = apmngr_db_get_template_max();
        local_30c = apmngr_db_get_sensor_max();
        local_30c = iVar4 + iVar5 + local_30c;
        local_308 = iVar3;
        FUN_004082d0(DAT_007cbef0,0xffffffff);
        iVar4 = *(int *)(DAT_007cbf08 + param_1 * 4);
        if ((iVar4 != 0) && (*(int *)(iVar4 + 0x10) != 0)) {
          FUN_00408570(iVar4,_ap_hash_info_collect,&local_310);
        }
        FUN_00407f30(DAT_007cbef0);
        iVar4 = apmngr_db_get_ap_max();
        iVar5 = apmngr_db_get_template_max();
        iVar6 = apmngr_db_get_sensor_max();
        iVar9 = 0;
        memset(__s,0,iVar4 + iVar5 + iVar6);
        while (iVar9 < local_310) {
          iVar5 = *(int *)(local_308 + iVar9 * 4);
          iVar4 = rdmngr_db_is_ap_all_rd_disabled(iVar5);
          if (iVar4 == 0) {
            __s[iVar5] = 1;
            if (g_wserv_debug == 0) {
              iVar9 = iVar9 + 1;
            }
            else {
              iVar4 = is_target_debug_ap();
              if (iVar4 == 0) {
                iVar9 = iVar9 + 1;
              }
              else {
                printf("<wserv>[warning]%s(): %d  -> bind vlan ap_id: %d tmp is 1!\r\n",
                       "wserv_db_for_each_l3_ap_unbind_vlan",0x13e7,iVar5);
                iVar9 = iVar9 + 1;
              }
            }
          }
          else {
            iVar9 = iVar9 + 1;
          }
        }
        FUN_00407df0(iVar3);
        uVar11 = 0;
        pbVar10 = __s;
        while( true ) {
          iVar3 = apmngr_db_get_ap_max();
          iVar4 = apmngr_db_get_template_max();
          iVar5 = apmngr_db_get_sensor_max();
          if (iVar3 + iVar4 + iVar5 <= (int)uVar11) {
            iVar2 = 0;
            while( true ) {
              iVar3 = apmngr_db_get_ap_max();
              iVar4 = apmngr_db_get_template_max();
              iVar5 = apmngr_db_get_sensor_max();
              if (iVar3 + iVar4 + iVar5 <= iVar2) break;
              if (__s[iVar2] == 1) {
                (*param_2)(iVar2,param_3);
                if (g_wserv_debug == 0) {
                  iVar2 = iVar2 + 1;
                }
                else {
                  iVar3 = is_target_debug_ap();
                  if (iVar3 == 0) {
                    iVar2 = iVar2 + 1;
                  }
                  else {
                    printf("<wserv>[warning]%s(): %d  -> tmp[%d] is 1, do cb\r\n",
                           "wserv_db_for_each_l3_ap_unbind_vlan",0x1408,iVar2);
                    iVar2 = iVar2 + 1;
                  }
                }
              }
              else {
                iVar2 = iVar2 + 1;
              }
            }
            return 0;
          }
          iVar3 = apmngr_db_capacity_support(uVar11 & 0xffff,1,0x38);
          if (iVar3 == 0) {
            *pbVar10 = 0;
            goto LAB_005f2de8;
          }
          iVar3 = apmngr_db_entry_get_by_id(uVar11 & 0xffff,auStack_300);
          if (iVar3 != 0) break;
          if (local_2e4 == 0) {
LAB_005f2de8:
            uVar11 = uVar11 + 1;
            pbVar10 = pbVar10 + 1;
          }
          else {
            bVar1 = *pbVar10;
            *pbVar10 = bVar1 + 1;
            if ((g_wserv_debug == 0) || (iVar3 = is_target_debug_ap(), iVar3 == 0))
            goto LAB_005f2de8;
            *(uint *)((int)auStack_320 + iVar2) = (uint)(byte)(bVar1 + 1);
            printf("<wserv>[warning]%s(): %d  -> used ap_id: %d tmp is %d!\r\n",
                   "wserv_db_for_each_l3_ap_unbind_vlan",0x13ff,uVar11);
            uVar11 = uVar11 + 1;
            pbVar10 = pbVar10 + 1;
          }
        }
        if (g_wserv_error == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        __format = "<wserv>[warning]%s(): %d  -> get ap_entry error!\r\n";
        uVar7 = 0x13f9;
      }
      uVar8 = 0xffffffff;
      printf(__format,"wserv_db_for_each_l3_ap_unbind_vlan",uVar7);
    }
  }
  else {
    uVar8 = 0xffffffff;
    if ((g_wserv_warning != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> vlan_id[%d] is invalid!\r\n",
             "wserv_db_for_each_l3_ap_unbind_vlan",0x13c9,param_1);
    }
  }
  return uVar8;
}

