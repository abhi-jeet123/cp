const jwt = require('jsonwebtoken');
const User = require('./../models/userModel');
const catchAsync = require('./../utils/catchAsync');
const dotenv = require('dotenv');
const AppError = require('./../utils/appError');

const signToken = id => {
  return jwt.sign({ id }, process.env.JWT_SECRET, {
    expiresIn: process.env.JWT_EXPIRES_IN
  });
};

exports.signUp = catchAsync(async (req, res, next) => {
  try {
    console.log('reached signup');
    const newUser = await User.create(req.body);
    console.log('newUser._id:', newUser._id);
    console.log('process.env.JWT_SECRET:', process.env.JWT_SECRET);
    console.log('process.env.JWT_EXPIRES_IN:', process.env.JWT_EXPIRES_IN);

    console.log('user created!!');
    const token = signToken(user._id);
    console.log('crossed SignUp');
    res.status(201).json({
      status: 'Success',
      token,
      data: {
        user: newUser
      }
    });
  } catch (error) {
    console.error('Token generation error:', error);
  }
});

exports.login = catchAsync(async (req, res, next) => {
  const { email, password } = req.body;

  //1) check the basic null handling
  if (!email || !password) {
    return next(new AppError('Please provide email and password!', 400));
  }
  //2) check if user exists and password is correct
  const user = await User.findOne({ email }).select('+password');
  console.log(user);
  console.log(password);
  console.log(user.password);
  const correctPassword = await user.correctPassword(password, user.password);
  if (!user || !correctPassword) {
    return next(new AppError('incorrect email or password', 401));
  }
  //3)If everything ok ,send token to client
  const token = signToken(user._id);

  res.status(200).json({
    status: 'success',
    token
  });
});

exports.protect = catchAsync(async (req, res, next) => {
  next();
});
