// func _uac_dhcpdef_jcs_set_bind_entries @ 00464e6c size=1456

void _uac_dhcpdef_jcs_set_bind_entries(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char *__dest;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  char *pcVar10;
  int *piVar11;
  undefined8 uVar12;
  
  iVar1 = json_object_object_get(param_1,"operation");
  if (iVar1 == 0) {
    if (g_dhcpdef_error != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar9 = 0xffffffff;
        goto LAB_00464f08;
      }
      printf("\x1b[31;49m[%s]<%s():%d> %s not found!\x1b[0m\r\n","dhcp_defend",
             "_uac_dhcpdef_jcs_set_bind_entries",0x606,"operation");
    }
LAB_00465148:
    uVar9 = 0xffffffff;
    goto LAB_00464f08;
  }
  iVar2 = json_object_get_type(iVar1);
  if (iVar2 == 3) {
    iVar1 = json_object_get_int(iVar1);
  }
  else {
    iVar2 = json_object_get_type();
    if (iVar2 == 2) {
      uVar12 = json_object_get_double(iVar1);
      iVar1 = __fixdfsi((int)((ulonglong)uVar12 >> 0x20),(int)uVar12);
    }
    else {
      iVar1 = -1;
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
               "_uac_dhcpdef_jcs_set_bind_entries",0x607);
      }
    }
  }
  if (2 < iVar1 - 3U) {
    uVar9 = 0xffffffff;
    if (g_dhcpdef_error != 0) {
      iVar2 = is_target_debug_ap(0xffffffff);
      if (iVar2 == 0) {
        uVar9 = 0xffffffff;
      }
      else {
        printf("\x1b[31;49m[%s]<%s():%d> Invalid JCS SET operation [%d]!\x1b[0m\r\n","dhcp_defend",
               "_uac_dhcpdef_jcs_set_bind_entries",0x60a,iVar1);
        uVar9 = 0xffffffff;
      }
    }
    goto LAB_00464f08;
  }
  puVar3 = (undefined4 *)FUN_004082a0(1000,4,0x60f);
  if (puVar3 == (undefined4 *)0x0) {
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
             "_uac_dhcpdef_jcs_set_bind_entries",0x612);
    }
    goto LAB_00465148;
  }
  __dest = (char *)FUN_00408450(0x1771,0x616);
  if (__dest == (char *)0x0) {
    if (g_dhcpdef_error == 0) {
LAB_004651dc:
      piVar5 = (int *)0x0;
      puVar7 = (undefined4 *)0x0;
    }
    else {
      iVar1 = is_target_debug_ap();
      piVar5 = (int *)0x0;
      if (iVar1 != 0) {
        pcVar10 = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
        uVar9 = 0x619;
        goto LAB_00465220;
      }
      puVar7 = (undefined4 *)0x0;
    }
LAB_004650f4:
    uVar9 = 0xffffffff;
  }
  else {
    iVar2 = json_object_object_get(param_1,"ap_id");
    if (iVar2 == 0) {
      piVar5 = (int *)0x0;
      if (g_dhcpdef_error == 0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          puVar7 = (undefined4 *)0x0;
        }
        else {
          printf("\x1b[31;49m[%s]<%s():%d> %s not found!\x1b[0m\r\n","dhcp_defend",
                 "_uac_dhcpdef_jcs_set_bind_entries",0x61e,"ap_id");
          puVar7 = (undefined4 *)0x0;
        }
      }
      goto LAB_004650f4;
    }
    memset(__dest,0,0x1771);
    iVar4 = json_object_get_type(iVar2);
    if (iVar4 == 6) {
      pcVar10 = (char *)json_object_get_string(iVar2);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_dhcpdef_jcs_set_bind_entries",0x620);
      }
      pcVar10 = "";
    }
    strncpy(__dest,pcVar10,6000);
    __dest[6000] = '\0';
    iVar2 = dhcpdef_util_str_split(__dest,&DAT_00678b90,puVar3,1000);
    if (iVar2 < 1) {
      piVar5 = (int *)0x0;
      if (g_dhcpdef_error == 0) goto LAB_004651dc;
      iVar1 = is_target_debug_ap();
      if (iVar1 != 0) {
        pcVar10 = "\x1b[31;49m[%s]<%s():%d> no ap is selected!\x1b[0m\r\n";
        uVar9 = 0x625;
        goto LAB_00465220;
      }
      puVar7 = (undefined4 *)0x0;
      goto LAB_004650f4;
    }
    piVar5 = (int *)FUN_004082a0(iVar2,4,0x629);
    if (piVar5 == (int *)0x0) {
      puVar7 = (undefined4 *)0x0;
      if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar10 = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
        uVar9 = 0x62c;
LAB_00465220:
        printf(pcVar10,"dhcp_defend","_uac_dhcpdef_jcs_set_bind_entries",uVar9);
        puVar7 = (undefined4 *)0x0;
      }
      goto LAB_004650f4;
    }
    iVar4 = 0;
    puVar7 = puVar3;
    piVar11 = piVar5;
    do {
      pcVar10 = (char *)*puVar7;
      iVar4 = iVar4 + 1;
      puVar7 = puVar7 + 1;
      iVar6 = atoi(pcVar10);
      *piVar11 = iVar6;
      piVar11 = piVar11 + 1;
    } while (iVar4 != iVar2);
    puVar7 = (undefined4 *)FUN_004082a0(iVar4,4,0x634);
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
      if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar10 = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
        uVar9 = 0x637;
        goto LAB_00465220;
      }
      goto LAB_004650f4;
    }
    iVar4 = 0;
    puVar8 = puVar7;
    do {
      iVar4 = iVar4 + 1;
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    } while (iVar4 != iVar2);
    if (iVar1 == 4) {
      uVar9 = 0;
LAB_004650dc:
      iVar1 = _uac_dhcpdef_batch_able_inner(uVar9,piVar5,iVar4,puVar7);
LAB_004650ec:
      uVar9 = 0;
      if (iVar1 != 0) goto LAB_004650f4;
    }
    else {
      uVar9 = 1;
      if (iVar1 != 5) goto LAB_004650dc;
      if ((g_dhcpdef_info != 0) && (iVar1 = is_target_debug_ap(piVar5), iVar1 != 0)) {
        printf("[%s]<%s():%d> -->IN: %s()\r\n","dhcp_defend","_uac_dhcpdef_batch_clear",0x5e5,
               "_uac_dhcpdef_batch_clear");
      }
      iVar4 = dhcpdef_db_apbind_entry_batch_clear_svrs(piVar5,iVar2,puVar7);
      iVar1 = -1;
      if (iVar4 == 0) {
        iVar1 = 0;
      }
      iVar2 = _uac_dhcpdef_batch_firm_and_notify(1,piVar5,iVar2,puVar7);
      uVar9 = 0xffffffff;
      if (iVar2 == 0) goto LAB_004650ec;
    }
  }
  FUN_00407df0(puVar3);
  if (__dest != (char *)0x0) {
    FUN_00407df0(__dest);
  }
  if (piVar5 != (int *)0x0) {
    FUN_00407df0(piVar5);
  }
  if (puVar7 != (undefined4 *)0x0) {
    FUN_00407df0(puVar7);
  }
LAB_00464f08:
  uVar9 = json_object_new_int(uVar9);
  json_object_object_add(param_2,"result",uVar9);
  return;
}

