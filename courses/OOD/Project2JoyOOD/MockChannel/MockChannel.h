#ifndef MOCKCHANNEL_H
#define MOCKCHANNEL_H

//////////////////////////////////////////////////////////////////////////////
// MockChannel.h - Demo for CSE687 Project #4, Spring 2017                  //
// - build as DLL to show how C++\CLI client can use native code channel    //
// - MockChannel reads from sendQ and writes to recvQ                       //
// Version     : 1.0                                                        //
// Language    : Visual C++, Visual Studio 2015                             //
// Platform    : Dell Inspiron 15 7000Series, Core-i5,                      //
//               Windows 10                                                 //
// Application : Code Publisher                                             //
// Author      : Joy Shalom Soosai Michael                                  //
//               jsoosaim@syr.edu,SUID : 699737418                          //
// Credits                                                                  //
// and source  : Dr.Jim Fawcett, Syracuse University                        //
//                      jfawcett@twcny.rr.com                               //
//////////////////////////////////////////////////////////////////////////////

// Credits
// --------
// I would like to give credits to Prof. Jim W Fawcett, Syracuse University
// for explaining how the remote code Publisher should work and giving a start up code.
/*
* Package Operations:
* -------------------
* This package builds as DLL to show how C++\CLI client can use native code channel 
* MockChannel reads from sendQ and writes to recvQ
*
* Required Files:
* ---------------
* MockChannel.h, Cpp11-BlockingQueue.h
*
* Build Process:
* --------------
* devenv MockChannel.sln /rebuild debug
*
* Maintenance History:
* --------------------
*  ver 1.0 - Build on top of Initial release by Prof. Jim Fawcett
*/

#ifdef IN_DLL
#define DLL_DECL __declspec(dllexport)
#else
#define DLL_DECL __declspec(dllimport)
#endif

#include <string>
using Message = std::string;

struct ISendr
{
  virtual void postMessage(const Message& msg) = 0;
};

struct IRecvr
{
  virtual std::string getMessage() = 0;
};

struct IMockChannel
{
public:
  virtual void start() = 0;
  virtual void stop() = 0;
};

extern "C" {
  struct ObjectFactory
  {
    DLL_DECL ISendr* createSendr();
    DLL_DECL IRecvr* createRecvr();
    DLL_DECL IMockChannel* createMockChannel(ISendr* pISendr, IRecvr* pIRecvr);
  };
}

#endif


