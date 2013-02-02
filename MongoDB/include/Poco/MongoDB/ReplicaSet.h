//
// ReplicaSet.h
//
// $Id$
//
// Library: MongoDB
// Package: MongoDB
// Module:  ReplicaSet
//
// Definition of the ReplicaSet class.
//
// Copyright (c) 2012, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//

#ifndef _MongoDB_ReplicaSet_h
#define _MongoDB_ReplicaSet_h

#include <vector>
#include "Poco/Net/SocketAddress.h"
#include "Poco/MongoDB/Connection.h"

namespace Poco
{
namespace MongoDB
{

class MongoDB_API ReplicaSet
{
public:
	ReplicaSet(const std::vector<Net::SocketAddress>& addresses);


	virtual ~ReplicaSet();


	Connection::Ptr findMaster();

private:

	Connection::Ptr isMaster(const Net::SocketAddress& host);


	std::vector<Net::SocketAddress> _addresses;
};

#endif // _MongoDB_ReplicaSet_h
}} // Poco::MongoDB
