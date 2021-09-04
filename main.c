#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet.h>
//we need to assemble the ICMP message with the required content and then send it as a payload of an IP datagram using a raw socket
//select req protocol no,create raw socket,set IP_HDRINCL socket option,construct datagram,send datagram



//we define the contants for the IP header
#define IP_HDRLEN 20;
#define  ICMP_HDRLEN 8;  //length of the echo request


cont char* protocol_name ="ICMP";



void main(){
    int status,datalen,sd,*ip_flags;
    char *interface,*target,*src_ip,*dst_ip;
    struct iphdr;
    struct icmp icmphdr;
    unsigned char *data,*packet;
    struct sockaddr_in *ipv4,sin;
    void *tmp;


    //assemble the  ICMP message with required payload
    //the maxpayload_size should be 65535,icmp header--8 bytes and ip header 20 bytes

tmp=(unsigned char *)malloc((IP_MAXPACKET-IP4_HDRLEN-ICMP_HDRLEN))* sizeof(usigned char));
if(tmp!=NULL){
    data=tmp;
}else{
    printf("unable to allocate memory for data",stderr);
    exit(EXIT_FAILURE);
}

    memset (data,0,(IP_MAXPACKET-IP4_HDRLEN-ICMP_HDRLEN)* sizeof (unsigned char));
    tmp=(char *) malloc(40* sizeof (char));
    if(tmp!=NULL){
        interface=tmp;
    }else{
        printf("unable to allocate memory to the interface\n",stderr);
        exit(EXIT_FAILIURE);
    }
    memset(interface,0,40* sizeof (char));


    tmp=(char *) malloc(40 * sizeof (char));
    if (tmp!=NILL){
   target=tmp;}else{
        fprintf("unable to alllocate memory to the target\n",stderr);
        exit(EXIT_FAILURE);
    }
    memset(target,0,40*sizeof(char));


    tmp=(char *) malloc(16 * sizeof(char));
    if(tmp!=NILL){
        src_ip=tmp;}else{
        frprintf("unable to ALLOCATE memory to the source address\n",stderr);
        exit(EXIT_FAILURE);
    }
    memset(src_ip,0,16* sizeof (char);

    tmp=(char *) malloc( 16 * sizeof (char));
    if (tmp!=NILL){
        dst_ip=tmp;
    }else{
        fprintf("unable to allocate memory to the dest_addr\n",stderr);
        exit(EXIT_FAILURE);
    }
    memset(dst_ip,0,16* sizeof(char));

    tmp(char *)malloc( 4* sizeof(char));
    if (tmp!=NILL){
        ip_flags=tmp;
    }else{
        fprintf("unable to allocate memory to the ip_flags\n",stderr);

        exit(EXIT_FAILURE);
    }
    memset(ip_flags,0,4* sizeof(char));


    //provide an interface for sending the packets
    strcpy(interface,"eth0");


    //the socket descriptor looks up for the interface
    //create the raw socket
    //sock_raw ==>the socket should provide direct access to the network layer without any transport layer

if ((sd=socket(AF_INET,SOCK_RAW,IPPROTO_ICMP))<0){
    perror("The socket failed to get socket descriptor using ioctl()");
    exit(EXIT_FAILURE);
}

//lookup for the interface using ioctl() method
    memset(&ifr,0,sizeof (ifr));
    snprintf(ifr.ifr_name,sizeof (ifr.ifr_name),interface);
    if (ioctl(sd,SIOCGIFINDEX,&ifr )){
        perror("ioctl() failed to locate the interface");
        return(exit_FAILURE);
    }
    close(sd);
    printf("The index for interface % s is %i\n",interface,ifr.ifr_ifrindex);




    //constructing the datagram
//the source ip adress and the destination url of the ip adrssses are specified
//raw datagrams can be sent thro any function that is capable of writing to a file descriptor
//we use sendto and sendmsg  inorder to specify the destination adress

const ICMP_HDRLEN =8;
struct icmphdr req;
req.type=8;
req.code=0;
req.checksum=0;
req.checksum=ip_checksum(&req,req_size);

//sending the datagram














}