// func radius_pair_add @ 00448fbc size=1108

char * radius_pair_add(undefined4 param_1,int *param_2,uint param_3,char *param_4,size_t param_5,
                      uint param_6)

{
  char *pcVar1;
  char *__dest;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  size_t sVar5;
  
  param_3 = param_6 << 0x10 | param_3;
  pcVar1 = (char *)radius_dict_getattr_by_value(param_1,param_3);
  if (pcVar1 == (char *)0x0) {
    if (radius_err_switch == 0) {
      return (char *)0x0;
    }
    uVar4 = 0x98;
    pcVar1 = "[RADIUS_ERR]%s()/%d rc_avpair_new: unknown attribute %d\n\n";
LAB_00449368:
    printf(pcVar1,"_radius_pair_new",uVar4,param_3);
    return (char *)0x0;
  }
  if ((param_6 != 0) && (iVar2 = radius_dict_getvend_by_value(param_1,param_6), iVar2 == 0)) {
    if (radius_err_switch == 0) {
      return (char *)0x0;
    }
    uVar4 = 0x9d;
    pcVar1 = "[RADIUS_ERR]%s()/%d rc_avpair_new: unknown Vendor-Id %d\n\n";
    param_3 = param_6;
    goto LAB_00449368;
  }
  __dest = (char *)uac_mem_malloc_my(0x154,0xa1);
  if (__dest == (char *)0x0) {
    if (radius_err_switch == 0) {
      return (char *)0x0;
    }
    printf("[RADIUS_ERR]%s()/%d Malloc error\n","_radius_pair_new",0xd1);
    return (char *)0x0;
  }
  pair_malloc = pair_malloc + 1;
  strncpy(__dest,pcVar1,0x40);
  *(uint *)(__dest + 0x44) = param_3;
  __dest[0x150] = '\0';
  __dest[0x151] = '\0';
  __dest[0x152] = '\0';
  __dest[0x153] = '\0';
  sVar5 = *(size_t *)(pcVar1 + 0x48);
  *(size_t *)(__dest + 0x48) = sVar5;
  switch(sVar5) {
  case 0:
    if (param_5 == 0xffffffff) {
      param_5 = strlen(param_4);
    }
    if ((int)param_5 < 0xfe) {
LAB_0044937c:
      memcpy(__dest + 0x50,param_4,param_5);
      __dest[param_5 + 0x50] = '\0';
      *(size_t *)(__dest + 0x4c) = param_5;
      goto LAB_0044922c;
    }
    if (radius_debug_switch == 0) goto LAB_0044909c;
    uVar4 = 0x56;
    pcVar1 = "[RADIUS_DEBUG]%s()/%d Len is too long: %d\n";
    break;
  case 1:
  case 2:
  case 3:
    *(undefined4 *)(__dest + 0x4c) = *(undefined4 *)param_4;
    goto LAB_0044922c;
  default:
    if (radius_debug_switch == 0) goto LAB_0044909c;
    uVar4 = 0x88;
    pcVar1 = "[RADIUS_DEBUG]%s()/%d Type not suppport: %d\n";
    param_5 = sVar5;
    break;
  case 5:
    if ((int)param_5 < 1) {
      if (radius_debug_switch == 0) goto LAB_0044909c;
      uVar4 = 0x60;
      pcVar1 = "[RADIUS_DEBUG]%s()/%d Len is error: %d\n";
    }
    else {
      if ((int)param_5 < 0xfe) goto LAB_0044937c;
      if (radius_debug_switch == 0) goto LAB_0044909c;
      uVar4 = 0x66;
      pcVar1 = "[RADIUS_DEBUG]%s()/%d Len is too long: %d\n";
    }
    break;
  case 6:
    sVar5 = 8;
    goto LAB_0044921c;
  case 7:
    sVar5 = 0x10;
LAB_0044921c:
    memcpy(__dest + 0x50,param_4,sVar5);
LAB_0044922c:
    if (*(int *)(__dest + 0x44) - 0x427U < 10) {
      if (0xfb < *(uint *)(__dest + 0x4c)) {
        __dest[0x4c] = '\0';
        __dest[0x4d] = '\0';
        __dest[0x4e] = '\0';
        __dest[0x4f] = -5;
      }
      memmove(__dest + 0x52,__dest + 0x50,*(size_t *)(__dest + 0x4c));
      __dest[0x50] = (char)*(undefined4 *)(__dest + 0x44) + -0x26;
      iVar2 = *(int *)(__dest + 0x4c);
      iVar3 = iVar2 + 2;
      *(int *)(__dest + 0x4c) = iVar3;
      __dest[0x51] = (char)iVar3;
      __dest[iVar2 + 0x52] = '\0';
      __dest[0x44] = '\0';
      __dest[0x45] = '\0';
      __dest[0x46] = '\0';
      __dest[0x47] = -0x31;
      iVar2 = *(int *)(__dest + 0x150);
    }
    else {
      iVar2 = *(int *)(__dest + 0x150);
    }
    if (iVar2 == 0) {
      if (*param_2 == 0) {
        *param_2 = (int)__dest;
      }
      else {
        FUN_00448f60(param_2,__dest);
      }
    }
    return __dest;
  case 8:
    if (param_5 - 2 < 0x11) {
      memcpy(__dest + 0x50,param_4,param_5);
      *(size_t *)(__dest + 0x4c) = param_5;
      goto LAB_0044922c;
    }
    if (radius_debug_switch == 0) goto LAB_0044909c;
    uVar4 = 0x80;
    pcVar1 = "[RADIUS_DEBUG]%s()/%d Len is error: %d\n";
  }
  printf(pcVar1,"_radius_pair_assign",uVar4,param_5);
LAB_0044909c:
  if (radius_debug_switch != 0) {
    printf("[RADIUS_DEBUG]%s()/%d Assign vp error\n","_radius_pair_new",200);
  }
  uac_mem_free_my(__dest);
  pair_free = pair_free + 1;
  return (char *)0x0;
}

