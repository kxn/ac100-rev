; func cloud_mngt_ap_data_free @ 0x0048bf08 size=0x50
  48bf08:	27bdffe0 	addiu	sp,sp,-32
  48bf0c:	afb00018 	sw	s0,24(sp)
  48bf10:	00808021 	move	s0,a0
  48bf14:	1080000c 	beqz	a0,0x48bf48
  48bf18:	afbf001c 	sw	ra,28(sp)
  48bf1c:	8c84001c 	lw	a0,28(a0)
  48bf20:	50800005 	beqzl	a0,0x48bf38
  48bf24:	02002021 	move	a0,s0
  48bf28:	0c101f7c 	jal	0x407df0
  48bf2c:	00000000 	nop
  48bf30:	ae00001c 	sw	zero,28(s0)
  48bf34:	02002021 	move	a0,s0
  48bf38:	8fbf001c 	lw	ra,28(sp)
  48bf3c:	8fb00018 	lw	s0,24(sp)
  48bf40:	08101f7c 	j	0x407df0
  48bf44:	27bd0020 	addiu	sp,sp,32
  48bf48:	8fbf001c 	lw	ra,28(sp)
  48bf4c:	8fb00018 	lw	s0,24(sp)
  48bf50:	03e00008 	jr	ra
  48bf54:	27bd0020 	addiu	sp,sp,32
