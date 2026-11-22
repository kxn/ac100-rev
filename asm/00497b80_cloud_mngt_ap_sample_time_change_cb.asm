; func cloud_mngt_ap_sample_time_change_cb @ 0x00497b80 size=0x60
  497b80:	27bdffe0 	addiu	sp,sp,-32
  497b84:	2c820004 	sltiu	v0,a0,4
  497b88:	afb00018 	sw	s0,24(sp)
  497b8c:	2410ffff 	li	s0,-1
  497b90:	1040000a 	beqz	v0,0x497bbc
  497b94:	afbf001c 	sw	ra,28(sp)
  497b98:	3c020076 	lui	v0,0x76
  497b9c:	8c4277dc 	lw	v0,30684(v0)
  497ba0:	10400006 	beqz	v0,0x497bbc
  497ba4:	00008021 	move	s0,zero
  497ba8:	3c020076 	lui	v0,0x76
  497bac:	8c4277d8 	lw	v0,30680(v0)
  497bb0:	00821025 	or	v0,a0,v0
  497bb4:	14400006 	bnez	v0,0x497bd0
  497bb8:	00000000 	nop
  497bbc:	8fbf001c 	lw	ra,28(sp)
  497bc0:	02001021 	move	v0,s0
  497bc4:	8fb00018 	lw	s0,24(sp)
  497bc8:	03e00008 	jr	ra
  497bcc:	27bd0020 	addiu	sp,sp,32
  497bd0:	0c123b87 	jal	0x48ee1c
  497bd4:	24840010 	addiu	a0,a0,16
  497bd8:	08125ef0 	j	0x497bc0
  497bdc:	8fbf001c 	lw	ra,28(sp)
