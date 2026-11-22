; func cw_priv_tdcp_passthrough_send_info_free @ 0x0057eef4 size=0x48
  57eef4:	27bdffe0 	addiu	sp,sp,-32
  57eef8:	afbf001c 	sw	ra,28(sp)
  57eefc:	afb00018 	sw	s0,24(sp)
  57ef00:	8c900010 	lw	s0,16(a0)
  57ef04:	12000009 	beqz	s0,0x57ef2c
  57ef08:	8fbf001c 	lw	ra,28(sp)
  57ef0c:	8e04000c 	lw	a0,12(s0)
  57ef10:	10800003 	beqz	a0,0x57ef20
  57ef14:	00000000 	nop
  57ef18:	0c101f7c 	jal	0x407df0
  57ef1c:	00000000 	nop
  57ef20:	0c101f7c 	jal	0x407df0
  57ef24:	02002021 	move	a0,s0
  57ef28:	8fbf001c 	lw	ra,28(sp)
  57ef2c:	00001021 	move	v0,zero
  57ef30:	8fb00018 	lw	s0,24(sp)
  57ef34:	03e00008 	jr	ra
  57ef38:	27bd0020 	addiu	sp,sp,32
