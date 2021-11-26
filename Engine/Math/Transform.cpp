#include "Transform.h"

namespace luck
{
	void Transform::Update()
	{
		Matrix33 mxs;
		mxs.Scale(scale);

		Matrix33 mxr;
		mxr.Rotate(rotation);

		Matrix33 mxt;
		mxt.Translate(position);

		matrix = mxs * mxr * mxt;
	}

	void Transform::Update(const Matrix33& mx)
	{
		Matrix33 mxs;
		mxs.Scale(localScale);

		Matrix33 mxr;
		mxr.Rotate(localRotation);

		Matrix33 mxt;
		mxt.Translate(localPosition);

		matrix = mxs * mxr * mxt * mx;

		position = matrix.GetTranslate();
		rotation = matrix.GetRotation();
		scale = matrix.GetScale();
	}

	bool Transform::Write(const rapidjson::Value& value) const
	{
		return false;
	}

	bool Transform::Read(const rapidjson::Value& value)
	{
		JSON_READ(value, position);
		JSON_READ(value, rotation);
		JSON_READ(value, scale);

		return true;
	}
}