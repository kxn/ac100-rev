; func cloud_mngt_client_data_free @ 0x0048beb8 size=0x50
  48beb8:	27bdffe0 	addiu	sp,sp,-32
  48bebc:	afb00018 	sw	s0,24(sp)
  48bec0:	00808021 	move	s0,a0
  48bec4:	1080000c 	beqz	a0,0x48bef8
  48bec8:	afbf001c 	sw	ra,28(sp)
  48becc:	8c840018 	lw	a0,24(a0)
  48bed0:	50800005 	beqzl	a0,0x48bee8
  48bed4:	02002021 	move	a0,s0
  48bed8:	0c101f7c 	jal	0x407df0
  48bedc:	00000000 	nop
  48bee0:	ae000018 	sw	zero,24(s0)
  48bee4:	02002021 	move	a0,s0
  48bee8:	8fbf001c 	lw	ra,28(sp)
  48beec:	8fb00018 	lw	s0,24(sp)
  48bef0:	08101f7c 	j	0x407df0
  48bef4:	27bd0020 	addiu	sp,sp,32
  48bef8:	8fbf001c 	lw	ra,28(sp)
  48befc:	8fb00018 	lw	s0,24(sp)
  48bf00:	03e00008 	jr	ra
  48bf04:	27bd0020 	addiu	sp,sp,32
