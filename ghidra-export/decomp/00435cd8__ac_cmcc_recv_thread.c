// func _ac_cmcc_recv_thread @ 00435cd8 size=1020

undefined4 _ac_cmcc_recv_thread(uint *param_1)

{
  uint __fd;
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  char *__format;
  sockaddr *__src;
  undefined4 uVar6;
  size_t __n;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  socklen_t local_118 [2];
  timeval local_110;
  sockaddr sStack_108;
  sockaddr sStack_f8;
  ushort local_e8;
  ushort local_e6;
  ushort local_e4;
  ushort local_e2;
  int local_dc;
  undefined1 auStack_d8 [28];
  void *local_bc;
  undefined4 local_b8;
  int local_b4;
  fd_set local_b0;
  uint local_30;
  
  local_118[1] = 0x10;
  local_118[0] = 0x1c;
  if (param_1 == (uint *)0x0) {
    return 0;
  }
LAB_00435d28:
  do {
    memset(&local_dc,0,0x2c);
    local_bc = (void *)FUN_00408450(0x640,0x135);
    __fd = cmcc_sockfd_v6;
    uVar10 = cmcc_sockfd;
  } while (local_bc == (void *)0x0);
  local_110.tv_usec = 0;
  local_110.tv_sec = 2;
  iVar1 = 0;
  do {
    puVar5 = (undefined4 *)((int)local_b0.fds_bits + iVar1);
    iVar1 = iVar1 + 4;
    *puVar5 = 0;
  } while (iVar1 != 0x80);
  uVar7 = cmcc_sockfd >> 5;
  uVar8 = cmcc_sockfd_v6 >> 5;
  uVar9 = cmcc_sockfd & 0x1f;
  local_b0.fds_bits[uVar7] = local_b0.fds_bits[uVar7] | 1 << uVar9;
  local_30 = cmcc_sockfd_v6 & 0x1f;
  local_b0.fds_bits[uVar8] = local_b0.fds_bits[uVar8] | 1 << (cmcc_sockfd_v6 & 0x1f);
  uVar2 = cmcc_sockfd;
  if ((int)cmcc_sockfd <= (int)cmcc_sockfd_v6) {
    uVar2 = cmcc_sockfd_v6;
  }
  iVar1 = select(uVar2 + 1,&local_b0,(fd_set *)0x0,(fd_set *)0x0,&local_110);
  if (iVar1 != 0) {
    if (iVar1 < 1) {
      if ((wportal_err_switch != 0) && (iVar3 = is_target_debug_ap(local_bc), iVar3 != 0)) {
        piVar4 = __errno_location();
        printf("[WPORTAL_ERR]%s()/%d select failed, ret=%d, errno=%d\n","_ac_cmcc_recv_thread",0x16a
               ,iVar1,*piVar4);
      }
      goto LAB_00435e80;
    }
    if ((local_b0.fds_bits[uVar7] >> uVar9 & 1U) == 0) {
      if ((local_b0.fds_bits[uVar8] >> (local_30 & 0x1f) & 1U) == 0) goto LAB_00435e80;
      iVar1 = recvfrom(__fd,local_bc,0x640,0,&sStack_f8,local_118);
      local_dc = 2;
    }
    else {
      iVar1 = recvfrom(uVar10,local_bc,0x640,0,&sStack_108,local_118 + 1);
      local_dc = 1;
    }
    iVar3 = local_dc;
    if (iVar1 - 0x10U < 0x3f1) goto LAB_00435f0c;
    if ((wportal_debug_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_00435e80;
    uVar6 = 0x172;
    __format = "[WPORTAL_DBG]%s()/%d Receive cmcc packet error\n";
    goto LAB_00435eb0;
  }
  goto LAB_00435e80;
LAB_00435f0c:
  local_b8 = 1;
  if (local_dc == 1) {
    __src = &sStack_108;
    __n = 0x10;
  }
  else {
    __src = &sStack_f8;
    __n = 0x1c;
  }
  local_b4 = iVar1;
  memcpy(auStack_d8,__src,__n);
  if (*param_1 == 0) {
    trap(7);
  }
  uVar10 = *(uint *)((int)local_bc + 8) % *param_1;
  if (iVar3 == 1) {
    if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d Receive cmcc packet src: %x, send to msg queue %d\n\n",
             "_ac_cmcc_recv_thread",0x188,sStack_108.sa_data._2_4_,uVar10);
    }
  }
  else if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d Receive cmcc packet src: %x:%x:%x:%x:%x:%x:%x:%x, send to msg queue %d\n\n"
           ,"_ac_cmcc_recv_thread",400,(uint)(ushort)sStack_f8.sa_data._6_2_,
           (uint)(ushort)sStack_f8.sa_data._8_2_,(uint)(ushort)sStack_f8.sa_data._10_2_,
           (uint)(ushort)sStack_f8.sa_data._12_2_,(uint)local_e8,(uint)local_e6,(uint)local_e4,
           (uint)local_e2,uVar10);
  }
  iVar1 = FUN_00407d40(*(undefined4 *)(_cmcc_threads + uVar10 * 8 + 4),&local_dc,0x2c,0,0);
  if (iVar1 == -1) {
    if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(local_bc), iVar1 != 0)) {
      __format = "[WPORTAL_DBG]%s()/%d Send to cmcc msgq error\n\n";
      uVar6 = 0x196;
LAB_00435eb0:
      printf(__format,"_ac_cmcc_recv_thread",uVar6);
    }
LAB_00435e80:
    FUN_00407df0(local_bc);
  }
  goto LAB_00435d28;
}

