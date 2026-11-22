// func _uac_md5_timer_add @ 0051cc48 size=1128

/* WARNING: Removing unreachable block (ram,0x0051cd90) */
/* WARNING: Removing unreachable block (ram,0x0051ce94) */
/* WARNING: Removing unreachable block (ram,0x0051cd5c) */
/* WARNING: Removing unreachable block (ram,0x0051ce48) */

undefined4
_uac_md5_timer_add(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                  char *param_6,undefined4 param_7)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *__format;
  undefined4 uVar7;
  int iVar8;
  
  uac_mutex_take(g_wheel_md5_timer_base,0xffffffff);
  iVar2 = uac_id_alloc(DAT_00783b00);
  if (-1 < iVar2) {
LAB_0051ccc8:
    iVar3 = WHEEL_MD5_TIMER_GET_BY_ID(iVar2);
    if ((iVar3 != 0) && ((*(byte *)(iVar3 + 0x54) & 1) == 0)) {
      do {
        bVar1 = 0xfff < (int)g_wheel_md5_timer_seq;
        uVar4 = g_wheel_md5_timer_seq;
        if (bVar1) {
          uVar4 = 0;
        }
        g_wheel_md5_timer_seq = g_wheel_md5_timer_seq + 1;
        if (bVar1) {
          g_wheel_md5_timer_seq = 1;
        }
      } while (*(uint *)(iVar3 + 0xc) >> 0x14 == uVar4);
      *(uint *)(iVar3 + 0xc) = uVar4 * 0x100000 + iVar2;
      strncpy((char *)(iVar3 + 0x10),param_6,0x40);
      *(undefined4 *)(iVar3 + 0x60) = param_3;
      *(undefined4 *)(iVar3 + 0x50) = param_7;
      *(undefined4 *)(iVar3 + 0x68) = param_4;
      iVar2 = DAT_007822e0;
      uVar4 = (uint)(param_1 * 1000 + param_2 / 1000) / 500;
      *(uint *)(iVar3 + 0x58) = uVar4;
      *(uint *)(iVar3 + 0x5c) = uVar4 + iVar2;
      *(byte *)(iVar3 + 0x54) = __md5_debug_bit | 1;
      *(undefined4 *)(iVar3 + 100) = param_5;
      internal_add_timer(iVar3);
      uac_mutex_give(g_wheel_md5_timer_base);
      if (wheel_md5_timer_debug_switch != '\0') {
        printf("[WHEEL_MD5_TIMER_DEBUG]%s()/%d Add a timer(%d) with interval %lu secs. %s-%d\n",
               "_uac_md5_timer_add",0x1dd,*(undefined4 *)(iVar3 + 0xc),
               (uint)(*(int *)(iVar3 + 0x58) * 500) / 1000,param_6,param_7);
        return *(undefined4 *)(iVar3 + 0xc);
      }
      return *(undefined4 *)(iVar3 + 0xc);
    }
    printf("[WHEEL_MD5_TIMER_ERROR]%s()/%d Should not happen for timer id %d\n","_uac_md5_timer_add"
           ,0x1c7,iVar2);
    uac_id_free(DAT_00783b00,iVar2);
    goto LAB_0051cefc;
  }
  iVar2 = (1 << (*(uint *)(PTR_DAT_007591ac + 0x2044) & 0x1f)) + -1;
  iVar8 = ((DAT_00783aec + iVar2) * 0x32) / 100;
  iVar3 = DAT_00783aec + iVar8;
  if (iVar3 + iVar2 < 0x100000) {
    iVar2 = uac_id_expand(DAT_00783b00,iVar8);
    if (iVar2 == -1) {
      uVar7 = 0x17a;
      __format = "[WHEEL_MD5_TIMER_ERROR]%s()/%d Failed to expand ID allocator.\n";
      goto LAB_0051cec8;
    }
    iVar2 = uac_mem_calloc_my(iVar8,0x6c,0x17f);
    if (iVar2 == 0) {
      uVar7 = 0x182;
      __format = "[WHEEL_MD5_TIMER_ERROR]%s()/%d Failed to alloc mem for extend timer array.\n";
      goto LAB_0051cec8;
    }
    if (DAT_00783ae8 == 0) {
      iVar5 = uac_mem_calloc_my(iVar3,4,0x187);
    }
    else {
      iVar5 = uac_mem_realloc(DAT_00783ae8,iVar3 * 4);
    }
    if (iVar5 != 0) {
      for (iVar6 = 0; iVar6 < iVar8; iVar6 = iVar6 + 1) {
        *(int *)(iVar5 + (iVar6 + DAT_00783aec) * 4) = iVar2;
        iVar2 = iVar2 + 0x6c;
      }
      DAT_00783af0 = DAT_00783af0 + 1;
      DAT_00783ae8 = iVar5;
      DAT_00783aec = iVar3;
      iVar2 = uac_id_alloc(DAT_00783b00);
      if (iVar2 < 0) {
        printf("[WHEEL_MD5_TIMER_ERROR]%s()/%d Failed to alloc id for new timer, maybe too many timers?\n"
               ,"_uac_md5_timer_add",0x1be);
        goto LAB_0051cefc;
      }
      goto LAB_0051ccc8;
    }
    printf("[WHEEL_MD5_TIMER_ERROR]%s()/%d Failed to alloc mem for extend timer array.\n",
           "_uac_timer_expand",399);
    uac_mem_free_my(iVar2);
  }
  else {
    uVar7 = 0x174;
    __format = 
    "[WHEEL_MD5_TIMER_ERROR]%s()/%d Failed to expand ID allocator because exceeds max num.\n";
LAB_0051cec8:
    printf(__format,"_uac_timer_expand",uVar7);
  }
  printf("[WHEEL_MD5_TIMER_ERROR]%s()/%d Failed to expand uac timer.\n","_uac_md5_timer_add",0x1b7);
LAB_0051cefc:
  uac_mutex_give(g_wheel_md5_timer_base);
  return 0xffffffff;
}

