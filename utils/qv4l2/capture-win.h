/* qv4l2: a control panel controlling v4l2 devices.
 *
 * Copyright (C) 2006 Hans Verkuil <hverkuil@xs4all.nl>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef CAPTURE_WIN_H
#define CAPTURE_WIN_H

#include "qv4l2.h"

#include <QWidget>
#include <QShortcut>
#include <QLabel>

class CaptureWin : public QWidget
{
	Q_OBJECT

public:
	CaptureWin();
	~CaptureWin();

	void setMinimumSize(int minw, int minh);
	virtual void setFrame(int width, int height, __u32 format,
			      unsigned char *data, const QString &info) = 0;

	virtual bool hasNativeFormat(__u32 format) = 0;
	static bool isSupported() { return false; }

protected:
	void closeEvent(QCloseEvent *event);
	void buildWindow(QWidget *videoSurface);

	QLabel m_information;

signals:
	void close();

private:
	QShortcut *m_hotkeyClose;

};
#endif
