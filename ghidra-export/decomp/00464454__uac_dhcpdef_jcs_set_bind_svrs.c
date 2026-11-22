// func _uac_dhcpdef_jcs_set_bind_svrs @ 00464454 size=2276

void _uac_dhcpdef_jcs_set_bind_svrs(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  char *__dest;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  char *pcVar11;
  char *pcVar12;
  undefined8 uVar13;
  undefined4 local_40 [2];
  int local_38;
  int local_34;
  int *local_30;
  
  local_40[0] = 0;
  iVar1 = json_object_object_get(param_1,"operation");
  if (iVar1 == 0) {
    if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("\x1b[31;49m[%s]<%s():%d> %s not found!\x1b[0m\r\n","dhcp_defend",
             "_uac_dhcpdef_jcs_set_bind_svrs",0x797,"operation");
    }
    piVar7 = (int *)0x0;
    puVar5 = (undefined4 *)0x0;
    pcVar11 = (char *)0x0;
    puVar4 = (undefined4 *)0x0;
    __dest = (char *)0x0;
LAB_004645cc:
    piVar8 = (int *)0x0;
  }
  else {
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 3) {
      local_34 = json_object_get_int(iVar1);
    }
    else {
      iVar2 = json_object_get_type();
      if (iVar2 == 2) {
        uVar13 = json_object_get_double(iVar1);
        local_34 = __fixdfsi((int)((ulonglong)uVar13 >> 0x20),(int)uVar13);
      }
      else {
        local_34 = -1;
        if (jcs_err_switch != 0) {
          printf("[JCS_ERR]%s()/%d Warning: Get int with error obj or value type is unmatch.\n",
                 "_uac_dhcpdef_jcs_set_bind_svrs",0x798);
        }
      }
    }
    if (1 < local_34 - 1U) {
      if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("\x1b[31;49m[%s]<%s():%d> Invalid JCS SET operation [%d]!\x1b[0m\r\n","dhcp_defend",
               "_uac_dhcpdef_jcs_set_bind_svrs",0x79b,local_34);
      }
      uVar3 = json_object_new_int(0xffffffff);
      json_object_object_add(param_2,"result",uVar3);
      return;
    }
    puVar4 = (undefined4 *)FUN_004082a0(1000,4,0x7a0);
    if (puVar4 == (undefined4 *)0x0) {
      if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
               "_uac_dhcpdef_jcs_set_bind_svrs",0x7a3);
      }
      piVar7 = (int *)0x0;
      puVar5 = (undefined4 *)0x0;
      pcVar11 = (char *)0x0;
      __dest = (char *)0x0;
      goto LAB_004645cc;
    }
    __dest = (char *)FUN_00408450(0x1771,0x7a7);
    if (__dest == (char *)0x0) {
      if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar11 = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
        uVar3 = 0x7aa;
LAB_004649e0:
        printf(pcVar11,"dhcp_defend","_uac_dhcpdef_jcs_set_bind_svrs",uVar3);
      }
LAB_00464934:
      piVar7 = (int *)0x0;
      puVar5 = (undefined4 *)0x0;
      pcVar11 = (char *)0x0;
      goto LAB_004645cc;
    }
    iVar1 = json_object_object_get(param_1,"ap_id");
    if (iVar1 == 0) {
      if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("\x1b[31;49m[%s]<%s():%d> %s not found!\x1b[0m\r\n","dhcp_defend",
               "_uac_dhcpdef_jcs_set_bind_svrs",0x7af,"ap_id");
      }
      goto LAB_00464934;
    }
    memset(__dest,0,0x1771);
    iVar2 = json_object_get_type(iVar1);
    if (iVar2 == 6) {
      pcVar11 = (char *)json_object_get_string(iVar1);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_dhcpdef_jcs_set_bind_svrs",0x7b1);
      }
      pcVar11 = "";
    }
    strncpy(__dest,pcVar11,6000);
    __dest[6000] = '\0';
    iVar1 = dhcpdef_util_str_split(__dest,&DAT_00678b90,puVar4,1000);
    if (iVar1 < 1) {
      if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar11 = "\x1b[31;49m[%s]<%s():%d> no ap is selected!\x1b[0m\r\n";
        uVar3 = 0x7b6;
        goto LAB_004649e0;
      }
      goto LAB_00464934;
    }
    puVar5 = (undefined4 *)FUN_004082a0(1000,4,0x7ba);
    if (puVar5 == (undefined4 *)0x0) {
      if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
               "_uac_dhcpdef_jcs_set_bind_svrs",0x7bd);
      }
      piVar7 = (int *)0x0;
      pcVar11 = (char *)0x0;
      goto LAB_004645cc;
    }
    pcVar11 = (char *)FUN_00408450(0x1771,0x7c1);
    if (pcVar11 == (char *)0x0) {
      if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar12 = "\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n";
        uVar3 = 0x7c4;
LAB_00464b5c:
        printf(pcVar12,"dhcp_defend","_uac_dhcpdef_jcs_set_bind_svrs",uVar3);
LAB_00464b64:
        piVar7 = (int *)0x0;
        goto LAB_004645cc;
      }
LAB_00464b28:
      piVar7 = (int *)0x0;
      goto LAB_004645cc;
    }
    iVar2 = json_object_object_get(param_1,"svr_id");
    if (iVar2 == 0) {
      if ((g_dhcpdef_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("\x1b[31;49m[%s]<%s():%d> %s not found!\x1b[0m\r\n","dhcp_defend",
               "_uac_dhcpdef_jcs_set_bind_svrs",0x7c9,"svr_id");
        goto LAB_00464b64;
      }
      goto LAB_00464b28;
    }
    memset(pcVar11,0,0x1771);
    iVar6 = json_object_get_type(iVar2);
    if (iVar6 == 6) {
      pcVar12 = (char *)json_object_get_string(iVar2);
    }
    else {
      if (jcs_err_switch != 0) {
        printf("[JCS_ERR]%s()/%d Warning: Get string with error obj or value type is unmatch.\n",
               "_uac_dhcpdef_jcs_set_bind_svrs",0x7cb);
      }
      pcVar12 = "";
    }
    strncpy(pcVar11,pcVar12,6000);
    pcVar11[6000] = '\0';
    iVar2 = dhcpdef_util_str_split(pcVar11,&DAT_00678b90,puVar5,1000);
    if (iVar2 < 1) {
      if (g_dhcpdef_error != 0) {
        iVar1 = is_target_debug_ap();
        if (iVar1 != 0) {
          pcVar12 = "\x1b[31;49m[%s]<%s():%d> no server is selected!\x1b[0m\r\n";
          uVar3 = 2000;
          goto LAB_00464b5c;
        }
        piVar7 = (int *)0x0;
        goto LAB_004645cc;
      }
      goto LAB_00464b28;
    }
    piVar7 = (int *)FUN_004082a0(iVar1,4,0x7d4);
    if (piVar7 == (int *)0x0) {
      if (g_dhcpdef_error == 0) goto LAB_004645cc;
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        piVar8 = (int *)0x0;
        goto LAB_004645d0;
      }
      uVar3 = 0x7d7;
      piVar8 = (int *)0x0;
LAB_00464ca8:
      puVar9 = (undefined4 *)0x0;
      printf("\x1b[31;49m[%s]<%s():%d> no memory!\x1b[0m\r\n","dhcp_defend",
             "_uac_dhcpdef_jcs_set_bind_svrs",uVar3);
      uVar3 = 0xffffffff;
      goto LAB_004645d4;
    }
    local_38 = 0;
    puVar9 = puVar4;
    piVar8 = piVar7;
    do {
      pcVar12 = (char *)*puVar9;
      puVar9 = puVar9 + 1;
      iVar6 = atoi(pcVar12);
      *piVar8 = iVar6;
      piVar8 = piVar8 + 1;
      local_38 = local_38 + 1;
    } while (local_38 != iVar1);
    piVar8 = (int *)FUN_004082a0(iVar2,4,0x7df);
    if (piVar8 != (int *)0x0) {
      local_38 = 0;
      puVar9 = puVar5;
      local_30 = piVar8;
      do {
        pcVar12 = (char *)*puVar9;
        puVar9 = puVar9 + 1;
        iVar6 = atoi(pcVar12);
        *local_30 = iVar6;
        local_30 = local_30 + 1;
        local_38 = local_38 + 1;
      } while (local_38 != iVar2);
      puVar9 = (undefined4 *)FUN_004082a0(iVar1,4,0x7ea);
      if (puVar9 != (undefined4 *)0x0) {
        iVar6 = 0;
        puVar10 = puVar9;
        do {
          iVar6 = iVar6 + 1;
          *puVar10 = 0;
          puVar10 = puVar10 + 1;
        } while (iVar6 < iVar1);
        if (local_34 == 2) {
          iVar1 = _uac_dhcpdef_batch_bind_inner(0,piVar7,iVar1,piVar8,iVar2,puVar9,local_40);
          uVar3 = 0xffffffff;
          if (iVar1 == 0) {
            uVar3 = 0;
          }
        }
        else {
          iVar1 = _uac_dhcpdef_batch_bind_inner(1,piVar7,iVar1,piVar8,iVar2,puVar9,local_40);
          uVar3 = json_object_new_int(local_40[0]);
          json_object_object_add(param_2,"bind_exceed",uVar3);
          uVar3 = 0xffffffff;
          if (iVar1 == 0) {
            uVar3 = 0;
          }
        }
        goto LAB_004645d4;
      }
      puVar9 = (undefined4 *)0x0;
      if (g_dhcpdef_error == 0) goto LAB_004645d0;
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar3 = 0xffffffff;
        goto LAB_004645d4;
      }
      uVar3 = 0x7ed;
      goto LAB_00464ca8;
    }
    puVar9 = (undefined4 *)0x0;
    if (g_dhcpdef_error != 0) {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar3 = 0xffffffff;
        goto LAB_004645d4;
      }
      uVar3 = 0x7e2;
      goto LAB_00464ca8;
    }
  }
LAB_004645d0:
  puVar9 = (undefined4 *)0x0;
  uVar3 = 0xffffffff;
LAB_004645d4:
  uVar3 = json_object_new_int(uVar3);
  json_object_object_add(param_2,"result",uVar3);
  if (puVar5 != (undefined4 *)0x0) {
    FUN_00407df0(puVar5);
  }
  if (pcVar11 != (char *)0x0) {
    FUN_00407df0(pcVar11);
  }
  if (puVar4 != (undefined4 *)0x0) {
    FUN_00407df0(puVar4);
  }
  if (__dest != (char *)0x0) {
    FUN_00407df0(__dest);
  }
  if (piVar7 != (int *)0x0) {
    FUN_00407df0(piVar7);
  }
  if (piVar8 != (int *)0x0) {
    FUN_00407df0(piVar8);
  }
  if (puVar9 != (undefined4 *)0x0) {
    FUN_00407df0(puVar9);
  }
  return;
}

