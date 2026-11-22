; func cloud_mngt_client_events_data_free @ 0x0048be68 size=0x50
  48be68:	27bdffe0 	addiu	sp,sp,-32
  48be6c:	afb00018 	sw	s0,24(sp)
  48be70:	00808021 	move	s0,a0
  48be74:	1080000c 	beqz	a0,0x48bea8
  48be78:	afbf001c 	sw	ra,28(sp)
  48be7c:	8c840018 	lw	a0,24(a0)
  48be80:	50800005 	beqzl	a0,0x48be98
  48be84:	02002021 	move	a0,s0
  48be88:	0c101f7c 	jal	0x407df0
  48be8c:	00000000 	nop
  48be90:	ae000018 	sw	zero,24(s0)
  48be94:	02002021 	move	a0,s0
  48be98:	8fbf001c 	lw	ra,28(sp)
  48be9c:	8fb00018 	lw	s0,24(sp)
  48bea0:	08101f7c 	j	0x407df0
  48bea4:	27bd0020 	addiu	sp,sp,32
  48bea8:	8fbf001c 	lw	ra,28(sp)
  48beac:	8fb00018 	lw	s0,24(sp)
  48beb0:	03e00008 	jr	ra
  48beb4:	27bd0020 	addiu	sp,sp,32
