// func cw_packet_queue_create @ 0059b340 size=740

int * cw_packet_queue_create(int param_1,int param_2,int param_3,char *param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  size_t sVar4;
  char *__s;
  
  piVar1 = (int *)FUN_00408450(0x10,0x72);
  if (piVar1 == (int *)0x0) {
    if (capwap_err_switch == 0) {
      return (int *)0x0;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return (int *)0x0;
    }
    printf("[CW_ERROR]%32s():%4d memory out.\n","cw_packet_queue_create",0x75);
    return (int *)0x0;
  }
  iVar2 = FUN_00408450(0x18,0x79);
  piVar1[3] = iVar2;
  if (iVar2 == 0) {
    if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_ERROR]%32s():%4d memory out.\n","cw_packet_queue_create",0x7c);
    }
  }
  else {
    uVar3 = FUN_00408450(param_1 << 2,0x82);
    *(undefined4 *)(iVar2 + 0x14) = uVar3;
    if (*(int *)(piVar1[3] + 0x14) == 0) {
      if ((capwap_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[CW_ERROR]%32s():%4d memory out.\n","cw_packet_queue_create",0x85);
      }
    }
    else {
      *(int *)(piVar1[3] + 0x10) = param_1;
      *(undefined4 *)piVar1[3] = 0;
      *(undefined4 *)(piVar1[3] + 4) = 0;
      *(undefined4 *)(piVar1[3] + 8) = 0;
      *(undefined4 *)(piVar1[3] + 0xc) = 0;
      iVar2 = 6;
      piVar1[1] = param_2;
      piVar1[2] = param_3;
      if (param_4 != (char *)0x0) {
        sVar4 = strlen(param_4);
        iVar2 = sVar4 + 6;
      }
      sVar4 = iVar2 + 1;
      __s = (char *)FUN_00408450(sVar4,0x94);
      if (__s != (char *)0x0) {
        if (param_4 == (char *)0x0) {
          snprintf(__s,sVar4,"%s","_mutex");
        }
        else {
          snprintf(__s,sVar4,"%s%s",param_4,"_mutex");
        }
        iVar2 = FUN_00407f00(__s,0);
        *piVar1 = iVar2;
        if (iVar2 != 0) {
          FUN_00407df0(__s);
          return piVar1;
        }
        if (capwap_err_switch == 0) {
          iVar2 = piVar1[3];
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            iVar2 = piVar1[3];
          }
          else {
            printf("[CW_ERROR]%32s():%4d uac mutex init failed.\n","cw_packet_queue_create",0xa9);
            iVar2 = piVar1[3];
          }
        }
        FUN_00407df0(*(undefined4 *)(iVar2 + 0x14));
        FUN_00407df0(piVar1[3]);
        goto LAB_0059b4f0;
      }
      if (capwap_err_switch == 0) {
        iVar2 = piVar1[3];
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          iVar2 = piVar1[3];
        }
        else {
          printf("[CW_ERROR]%32s():%4d memory out.\n","cw_packet_queue_create",0x97);
          iVar2 = piVar1[3];
        }
      }
      FUN_00407df0(*(undefined4 *)(iVar2 + 0x14));
    }
    FUN_00407df0(piVar1[3]);
    piVar1[3] = 0;
  }
LAB_0059b4f0:
  FUN_00407df0(piVar1);
  return (int *)0x0;
}

