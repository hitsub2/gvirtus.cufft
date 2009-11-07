/* 
 * File:   VmciCommunicator.h
 * Author: cjg
 *
 * Created on November 4, 2009, 2:50 PM
 */

#ifndef _VMCICOMMUNICATOR_H
#define	_VMCICOMMUNICATOR_H

#include <vmci/vmci_sockets.h>
#include <ext/stdio_filebuf.h>
#include "Communicator.h"

#define AF_VMCI VMCISock_GetAFValue()

class VmciCommunicator : public Communicator {
public:
    VmciCommunicator(short port);
    VmciCommunicator(unsigned fd);
    virtual ~VmciCommunicator();
    void Serve();
    const Communicator * const Accept() const;
    void Connect();
    std::istream & GetInputStream() const;
    std::ostream & GetOutputStream() const;
    void Close();
private:
    void InitializeStream();
    std::istream *mpInput;
    std::ostream *mpOutput;
    short mPort;
    int mSocketFd;
    __gnu_cxx::stdio_filebuf<char> *mpInputBuf;
    __gnu_cxx::stdio_filebuf<char> *mpOutputBuf;
};

#endif	/* _VMCICOMMUNICATOR_H */
