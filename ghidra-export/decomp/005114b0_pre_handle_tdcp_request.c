// func pre_handle_tdcp_request @ 005114b0 size=1240

undefined4
pre_handle_tdcp_request
          (undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  char *pcVar9;
  undefined4 *puVar10;
  char local_40 [16];
  undefined4 *local_30;
  
  if (tdcp_debug_switch != 0) {
    printf("[TDCP_DEBUG]%s()/%d enter pre_handle_tdcp_request\n","pre_handle_tdcp_request",0x17c);
  }
  builtin_strncpy(local_40,"method",7);
  local_40[7] = 0;
  local_40[8] = 0;
  local_40[9] = 0;
  iVar1 = jsonParseStr(param_1);
  if ((iVar1 == 0) || (param_4 == (undefined4 *)0x0)) {
    if (tdcp_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[TDCP_ERROR]%s()/%d jsonObj or name or op is NULL!\n\n","pre_handle_tdcp_request",0x189)
    ;
    return 0xffffffff;
  }
  iVar2 = json_object_get_object(iVar1);
  pcVar8 = (char *)0x0;
  puVar10 = *(undefined4 **)(iVar2 + 0x20);
  while (puVar10 != (undefined4 *)0x0) {
    iVar2 = puVar10[1];
    while( true ) {
      pcVar9 = (char *)*puVar10;
      puVar10 = (undefined4 *)puVar10[2];
      if (iVar2 == 0) {
        if (tdcp_err_switch != 0) {
          printf("[TDCP_ERROR]%s()/%d parsed jsonObj failed!\n","pre_handle_tdcp_request",0x194);
        }
        uVar5 = 0xffffffff;
        iVar2 = 0;
        goto LAB_00511804;
      }
      if (tdcp_debug_switch != 0) {
        printf("[TDCP_DEBUG]%s()/%d the key is %s\n","pre_handle_tdcp_request",0x199,pcVar9);
      }
      iVar3 = json_object_get_type(iVar2);
      iVar4 = strcmp(pcVar9,local_40);
      if (iVar4 == 0) break;
      if (iVar3 == 6) {
        uVar5 = json_object_get_string(iVar2);
        *param_2 = uVar5;
      }
      else {
        uVar5 = json_object_to_json_string();
        *param_2 = uVar5;
      }
      if (puVar10 == (undefined4 *)0x0) goto LAB_005115b0;
      iVar2 = puVar10[1];
    }
    if (iVar3 == 6) {
      pcVar8 = (char *)json_object_get_string(iVar2);
    }
    else {
      pcVar8 = (char *)json_object_to_json_string();
    }
  }
LAB_005115b0:
  iVar2 = jsonParseStr(*param_2);
  if (iVar2 == 0) {
    uVar5 = 0xffffffff;
    if (tdcp_err_switch == 0) goto LAB_00511804;
    pcVar8 = "[TDCP_ERROR]%s()/%d jsonObj or name or op is NULL!\n\n";
    uVar7 = 0x1b8;
  }
  else {
    iVar3 = json_object_get_object(iVar2);
    puVar10 = *(undefined4 **)(iVar3 + 0x20);
    if (puVar10 == (undefined4 *)0x0) {
LAB_00511644:
      if (tdcp_debug_switch != 0) {
        printf("[TDCP_DEBUG]%s()/%d tdcp_op_str:%s\n","pre_handle_tdcp_request",0x1e8,pcVar8);
      }
      if (pcVar8 != (char *)0x0) {
        iVar3 = strcmp(pcVar8,"get");
        uVar7 = 1;
        if (iVar3 != 0) {
          iVar3 = strcmp(pcVar8,"set");
          uVar7 = 2;
          if (iVar3 != 0) {
            iVar3 = strcmp(pcVar8,"add");
            uVar7 = 3;
            if (iVar3 != 0) {
              iVar3 = strcmp(pcVar8,"delete");
              uVar7 = 4;
              if (iVar3 != 0) {
                iVar3 = strcmp(pcVar8,"do");
                uVar7 = 5;
                if (iVar3 != 0) {
                  if (tdcp_err_switch != 0) {
                    pcVar8 = "[TDCP_ERROR]%s()/%d get op failed!\n";
                    uVar5 = 0x153;
                    goto LAB_0051193c;
                  }
                  goto LAB_005116e0;
                }
              }
            }
          }
        }
        *param_4 = uVar7;
        if (tdcp_debug_switch == 0) {
          uVar5 = 0;
        }
        else {
          uVar5 = 0;
          printf("[TDCP_DEBUG]%s()/%d pre handle json_str:%s,tdcp_type:%s,op:%d\n",
                 "pre_handle_tdcp_request",499,*param_2,*param_3,uVar7);
        }
        goto LAB_00511804;
      }
      if (tdcp_err_switch != 0) {
        pcVar8 = "[TDCP_ERROR]%s()/%d tdcp_op_str is NULL\n";
        uVar5 = 0x139;
LAB_0051193c:
        printf(pcVar8,"_tdcp_get_op",uVar5);
      }
LAB_005116e0:
      uVar5 = 0xffffffff;
      if (tdcp_err_switch == 0) goto LAB_00511804;
      pcVar8 = "[TDCP_ERROR]%s()/%d get op failed!\n";
      uVar7 = 0x1ec;
    }
    else {
      pcVar9 = (char *)*puVar10;
      local_30 = puVar10;
      while( true ) {
        iVar3 = local_30[1];
        local_30 = (undefined4 *)local_30[2];
        if (iVar3 == 0) break;
        if (tdcp_debug_switch != 0) {
          printf("[TDCP_DEBUG]%s()/%d the mainObj key is %s\n","pre_handle_tdcp_request",0x1c7,
                 pcVar9);
        }
        *param_3 = pcVar9;
        iVar4 = json_object_get_type(iVar3);
        iVar6 = strcmp(pcVar9,"table");
        if ((iVar6 == 0) || (iVar6 = strcmp(pcVar9,"name"), iVar6 == 0)) {
          if (iVar4 == 6) {
            uVar5 = json_object_get_string(iVar3);
            *param_3 = uVar5;
          }
          else {
            uVar5 = json_object_to_json_string();
            *param_3 = uVar5;
          }
          goto LAB_00511644;
        }
        if (local_30 == (undefined4 *)0x0) goto LAB_00511644;
        pcVar9 = (char *)*local_30;
      }
      uVar5 = 0xffffffff;
      if (tdcp_err_switch == 0) goto LAB_00511804;
      pcVar8 = "[TDCP_ERROR]%s()/%d parsed mainObj failed!\n";
      uVar7 = 0x1c2;
    }
  }
  uVar5 = 0xffffffff;
  printf(pcVar8,"pre_handle_tdcp_request",uVar7);
LAB_00511804:
  json_object_put(iVar1);
  if (iVar2 != 0) {
    json_object_put(iVar2);
  }
  return uVar5;
}

